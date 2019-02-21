from math import copysign, sqrt
from tkinter import *
import PIL
from functools import partial
from PIL import ImageTk, Image
import random
import time
from winsound import PlaySound, SND_LOOP, SND_ASYNC, SND_PURGE


FILENAME = "26-tennis.jpg"
WIDTH = 900
HEIGHT = 500


def point_distance(p1x, p1y, p2x, p2y):
    return sqrt((p2x - p1x) ** 2 + (p2y - p1y) ** 2)


class Player:
    PAD_SIZE = (60, 100)  # wight, height
    MAX_PAD_SPEED = 40

    def __init__(self, side, color, game):
        self.pad_speed = 0

        self.game = game
        pad_width, pad_height = self.PAD_SIZE
        field_width, field_height = self.game.field_size
        self.canvas = self.game.canvas

        if side == 'left':
            pad_x = 0
            text_x = field_width / 6
        else:
            pad_x = field_width - pad_width
            text_x = field_width - field_width / 6

        self.pad = self.canvas.create_line(
            pad_x + pad_width / 2, 0,
            pad_x + pad_width / 2, pad_height,
            width=pad_width, fill=color
        )
        self.side = side

        self.score = 0
        self.score_text = self.canvas.create_text(
            text_x, field_height / 4,
            text=self.score,
            font="Arial 20",
            fill="white"
        )

        if side == 'left':
            self.canvas.create_line(
                pad_x + pad_width, 0,
                pad_x + pad_width, field_height,
                fill="white"
            )
        else:
            self.canvas.create_line(
                pad_x, 0,
                pad_x, field_height,
                fill="white"
            )

    def get_pad_position(self):
        left, top, right, bot = self.canvas.coords(self.pad)
        pad_x = (left + right) / 2
        pad_y = (top + bot) / 2
        return pad_x, pad_y

    def tick(self):
        self.tick_move()

    def tick_move(self):
        self.canvas.move(self.pad, 0, self.pad_speed)

        # проверить невыход за границы:
        x1, y1, x2, y2 = self.canvas.coords(self.pad)
        _, field_height = self.game.field_size
        if y1 < 0:
            # pad оказался выше поле
            self.canvas.move(self.pad, 0, -y1)
        elif y2 > field_height:
            # pad оказался ниже поле
            self.canvas.move(self.pad, 0, field_height - y2)

    def should_hit(self, x, y, radius):
        pad_left, _, pad_right, _ = self.canvas.coords(self.pad)
        if self.side == 'left':
            is_hit_x = x - radius <= pad_right
        else:
            is_hit_x = x + radius >= pad_left
        return is_hit_x

    def is_hit(self, x, y, radius):
        pad_left, pad_top, pad_right, pad_bot = self.canvas.coords(self.pad)
        if self.side == 'left':
            is_hit_y = point_distance(pad_right, pad_top, x, y) <= radius or \
                       point_distance(pad_right, pad_bot, x, y) <= radius
        else:
            is_hit_y = point_distance(pad_left, pad_top, x, y) <= radius or \
                       point_distance(pad_left, pad_bot, x, y) <= radius
        return is_hit_y or pad_top <= y <= pad_bot

    def update_score(self):
        self.score += 1
        self.canvas.itemconfig(self.score_text, text=self.score)


class AutoPlayer(Player):
    def on_key_press(self, event):
        pass

    def on_key_release(self, event):
        pass

    def tick(self):
        _, pad_y = self.get_pad_position()
        _, ball_y = self.game.ball.get_next_position()
        if abs(ball_y - pad_y) > self.PAD_SIZE[1]/2.5:
            self.pad_speed = copysign(self.MAX_PAD_SPEED, ball_y - pad_y)
        else:
            self.pad_speed = 0
        super().tick()


class HumanPlayer(Player):
    def __init__(self, movement_keysyms, **kwargs):
        super().__init__(**kwargs)
        self.movement_keysyms = movement_keysyms

    def on_key_press(self, event):
        up_keysym, down_keysym = self.movement_keysyms
        if event.keysym == up_keysym:
            self.pad_speed = -self.MAX_PAD_SPEED
        elif event.keysym == down_keysym:
            self.pad_speed = self.MAX_PAD_SPEED

    def on_key_release(self, event):
        if event.keysym in self.movement_keysyms:
            # остановить, так как юзер отпустил клавишу
            self.pad_speed = 0


class Ball:
    RADIUS = 25

    SPEED_UP = 1.05
    MAX_SPEED = 40
    INITIAL_SPEED = 20

    def __init__(self, game, prev_speed=None):
        field_width, field_height = game.field_size
        self.canvas = game.canvas
        self.ball = self.canvas.create_oval(
            field_width / 2 - self.RADIUS,
            field_height / 2 - self.RADIUS,
            field_width / 2 + self.RADIUS,
            field_height / 2 + self.RADIUS,
            fill="white"
        )

        x_speed = self.INITIAL_SPEED
        y_speed = self.INITIAL_SPEED
        if prev_speed:
            # сохранить направление мяча
            x_speed *= prev_speed[0] / abs(prev_speed[0])

        self.speed = (x_speed, y_speed)
        self.game = game

    def strike_bounce(self):
        x_speed, y_speed = self.speed
        y_speed = random.randrange(-10, 10)
        if abs(x_speed) < self.MAX_SPEED:
            # увеличить скорость по x с инвертированием направления
            x_speed *= -self.SPEED_UP
        else:
            # инвертировать направление по x
            x_speed *= -1
        self.speed = x_speed, y_speed

    def ricochet_bounce(self):
        x_speed, y_speed = self.speed
        y_speed *= -1
        self.speed = x_speed, y_speed

    def get_position(self):
        ball_left, ball_top, ball_right, ball_bot = self.canvas.coords(self.ball)
        ball_x = (ball_left + ball_right) / 2
        ball_y = (ball_top + ball_bot) / 2
        return ball_x, ball_y

    def get_next_position(self):
        x_speed, y_speed = self.speed
        ball_x, ball_y = self.get_position()
        ball_x += x_speed
        ball_y += y_speed
        return ball_x, ball_y

    def tick_move(self):
        _, field_height = self.game.field_size
        ball_next_x, ball_next_y = self.get_next_position()
        if ball_next_y + self.RADIUS > field_height or ball_next_y - self.RADIUS < 0:
            self.ricochet_bounce()

        x_speed, y_speed = self.speed
        self.canvas.move(self.ball, x_speed, y_speed)


class Game:
    def __init__(self, canvas, field_size, player_count=1):
        self.canvas = canvas
        self.field_size = field_size
        self.ball = None

        self.players = [self.create_human_player('right')]
        if player_count == 1:
            self.players.append(self.create_auto_player('left'))
        elif player_count == 2:
            self.players.append(self.create_human_player('left'))

        field_width, field_height = field_size
        canvas.create_line(
            field_width / 2, 0,
            field_width / 2, field_height,
            fill="black"
        )

        self.stopped = False

        self.recreate_ball()

        self.canvas.bind('<KeyPress>', self.on_key_press)
        self.canvas.bind('<KeyRelease>', self.on_key_release)

    def stop(self):
        self.stopped = True

    def create_human_player(self, side):
        if side == 'right':
            movement_keysyms = ('Up', 'Down')
            color = 'red'
        else:
            movement_keysyms = ('r', 'f')
            color = 'grey'
        return HumanPlayer(
            movement_keysyms=movement_keysyms,
            side=side,
            color=color,
            game=self
        )

    def create_auto_player(self, side):
        if side == 'right':
            color = 'red'
        else:
            color = 'grey'
        return AutoPlayer(
            side=side,
            color=color,
            game=self
        )

    def recreate_ball(self):
        if self.ball:
            self.canvas.delete(self.ball.ball)
            self.ball = Ball(self, prev_speed=self.ball.speed)
        else:
            self.ball = Ball(self)

    def tick(self):
        if self.stopped:
            return

        ball_x, ball_y = self.ball.get_next_position()
        ball_radius = self.ball.RADIUS

        player_1, player_2 = self.players
        for player in self.players:
            player.tick()
            if player.should_hit(ball_x, ball_y, ball_radius):
                if player.is_hit(ball_x, ball_y, ball_radius):
                    self.ball.strike_bounce()
                else:
                    if player is player_1:
                        player_2.update_score()
                    else:
                        player_1.update_score()
                    self.recreate_ball()

        self.ball.tick_move()

        # зациклить тик
        self.canvas.after(40, self.tick)

    def on_key_press(self, event):
        for player in self.players:
            player.on_key_press(event)

    def on_key_release(self, event):
        for player in self.players:
            player.on_key_release(event)


### Menu window ###

app_root = Tk()


def new_game(player_count=1):
    global game
    PlaySound(None, SND_PURGE)
    match_window.deiconify()
    app_root.withdraw()
    c = Canvas(match_window, width=WIDTH, height=HEIGHT, background="#126868")
    c.pack()
    c.focus_set()
    game = Game(c, field_size=(WIDTH, HEIGHT), player_count=player_count)
    game.tick()  # start game tick looping


def show_menu():
    match_window.withdraw()
    app_root.deiconify()
    game.stop()
    game.canvas.destroy()
    play_sound()


def play_sound():
    PlaySound('Hans_Zimmer_Alex_on_The_Spot_-_Hans_Zimmer_Alex_on_The_Spot.wav', SND_LOOP | SND_ASYNC)


bg_img = ImageTk.PhotoImage(Image.open(FILENAME))

play_sound()

app_root.title("Ping-Pong Game")
app_root.geometry("900x500+400+50")
app_root.update()

menu_frame = Canvas(app_root,bg="#425")
menu_frame.pack(expand=True, fill='both')

bg = Canvas(menu_frame, bg='#425')
bg.place(relx=.5, rely=.5, width=bg_img.width(), height=bg_img.height(), anchor="c")
bg.create_image(0, 0, image=bg_img, anchor="nw")

# Label(menu_frame, text=FILENAME).pack()

new_game1_btn = Button(menu_frame,
             text="1 player",
             background="#425",
             foreground="#ccc",
             font="16",
             command=partial(new_game, 1))

new_game_btn = Button(menu_frame,
             text="2 players",
             background="#425",
             foreground="#ccc",
             font="17",
             command=partial(new_game, 2))


exit_btn = Button(menu_frame,
             text="Exit",
             background="#425",
             foreground="#ccc",
             font="18",
             command=app_root.destroy)


new_game1_btn.place(relx=.5, rely=.3, relwidth=.2, relheight=.12, anchor="c")
new_game_btn.place(relx=.5, rely=.5, relwidth=.2, relheight=.12, anchor="c")
exit_btn.place(relx=.5, rely=.7, relwidth=.2, relheight=.12, anchor="c")


### Match window ###

match_window = Toplevel(app_root)
match_window.title("Ping-Pong match")
match_window.geometry('900x500+400+50')
match_window.withdraw()
match_window.protocol("WM_DELETE_WINDOW", show_menu)

app_root.mainloop()
