from tkinter import *
import PIL
from PIL import ImageTk, Image
import random
import time


FILENAME = "26-tennis.jpg"

WIDTH = 900
HEIGHT = 500


game_started = False


### Menu window ###

app_root = Tk()


def new_game(player_count=1):
    global game_started
    game_started = True
    match_window.deiconify()
    app_root.withdraw()
    game_tick()  # start game tick looping

def show_menu():
    global game_started
    match_window.withdraw()
    app_root.deiconify()
    game_started = False  # stop game loop


bg_img = ImageTk.PhotoImage(Image.open(FILENAME))

app_root.title("Ping-Pong Game")
app_root.geometry("900x500+400+50")
app_root.update()

menu_frame = Canvas(app_root,bg="#425")
menu_frame.pack(expand=True, fill='both')

bg = Canvas(menu_frame, bg='#425', )
bg.place(relx=0.5, rely=0.5, width=bg_img.width(), height=bg_img.height(), anchor="c")
bg.create_image(0, 0, image=bg_img, anchor="nw")

# Label(menu_frame, text=FILENAME).pack()

new_game1_btn = Button(menu_frame,
             text="1 player",
             background="#425",
             foreground="#ccc",
             font="16",
             command=new_game)

new_game_btn = Button(menu_frame,
             text="2 players",
             background="#425",
             foreground="#ccc",
             font="17",
             command=new_game)


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

PAD_W = 60
PAD_H = 100

BALL_SPEED_UP = 1.05
BALL_MAX_SPEED = 40
BALL_RADIUS = 55

INITIAL_SPEED = 20
ball_x_speed = INITIAL_SPEED
ball_y_speed = INITIAL_SPEED

player_1_score = 0
player_2_score = 0

right_line_distance = WIDTH - PAD_W


def update_score(player):
    global player_1_score, player_2_score
    if player == "right":
        player_1_score += 1
        c.itemconfig(p_1_text, text=player_1_score)
    else:
        player_2_score += 1
        c.itemconfig(p_2_text, text=player_2_score)


def spawn_ball():
    global ball_x_speed
    c.coords(BALL, WIDTH / 2 - BALL_RADIUS / 2,
             HEIGHT / 2 - BALL_RADIUS / 2,
             WIDTH / 2 + BALL_RADIUS / 2,
             HEIGHT / 2 + BALL_RADIUS / 2)
    ball_x_speed = -(ball_x_speed * -INITIAL_SPEED) / abs(ball_x_speed)

def bounce(action):
    global ball_x_speed, ball_y_speed
    if action == "strike":
        ball_y_speed = random.randrange(-10, 10)
        if abs(ball_x_speed) < BALL_MAX_SPEED:
            ball_x_speed *= -BALL_SPEED_UP
        else:
            ball_x_speed = -ball_x_speed
    else:
        ball_y_speed = -ball_y_speed


match_window = Toplevel(app_root)
match_window.title("Ping-Pong match")
match_window.geometry('900x500+400+50')
match_window.withdraw()
match_window.protocol("WM_DELETE_WINDOW", show_menu)

c = Canvas(match_window, width=WIDTH, height=HEIGHT, background="#126868")
c.pack()


c.create_line(PAD_W, 0, PAD_W, HEIGHT, fill="white")
c.create_line(WIDTH - PAD_W, 0, WIDTH - PAD_W, HEIGHT, fill="white")
c.create_line(WIDTH / 2, 0, WIDTH / 2, HEIGHT, fill="black")

BALL = c.create_oval(WIDTH / 2 - BALL_RADIUS / 2,
                     HEIGHT / 2 - BALL_RADIUS / 2,
                     WIDTH / 2 + BALL_RADIUS / 2,
                     HEIGHT / 2 + BALL_RADIUS / 2, fill="white")
LEFT_PAD = c.create_line(PAD_W / 2, 0, PAD_W / 2, PAD_H, width=PAD_W, fill="grey")

RIGHT_PAD = c.create_line(WIDTH - PAD_W / 2, 0, WIDTH - PAD_W / 2,PAD_H, width=PAD_W, fill="red")

p_1_text = c.create_text(WIDTH - WIDTH / 6, PAD_H / 4,
                         text=player_1_score,
                         font="Arial 20",
                         fill="white")

p_2_text = c.create_text(WIDTH / 6, PAD_H / 4,
                         text=player_2_score,
                         font="Arial 20",
                         fill="white")

BALL_X_CHANGE = 20
BALL_Y_CHANGE = 0

def move_ball():
    ball_left, ball_top, ball_right, ball_bot = c.coords(BALL)
    ball_center = (ball_top + ball_bot) / 2

    if ball_right + ball_x_speed < right_line_distance and \
            ball_left + ball_x_speed > PAD_W:
        c.move(BALL, ball_x_speed, ball_y_speed)

    elif ball_right == right_line_distance or ball_left == PAD_W:
        if ball_right > WIDTH / 2:
            if c.coords(RIGHT_PAD)[1] < ball_center < c.coords(RIGHT_PAD)[3]:
                bounce("strike")
            else:
                update_score("left")
                spawn_ball()
        else:
            if c.coords(LEFT_PAD)[1] < ball_center < c.coords(LEFT_PAD)[3]:
                bounce("strike")
            else:
                update_score("right")
                spawn_ball()

    else:
        if ball_right > WIDTH / 2:
            c.move(BALL, right_line_distance - ball_right, ball_y_speed)
        else:
            c.move(BALL, -ball_left + PAD_W, ball_y_speed)
    if ball_top + ball_y_speed < 0 or ball_bot + ball_y_speed > HEIGHT:
        bounce("ricochet")


PAD_SPEED = 20
left_pad_speed = 0
right_pad_speed = 0

def move_pads():
    PADS = {LEFT_PAD: left_pad_speed,
            RIGHT_PAD: right_pad_speed}
    for pad in PADS:
        c.move(pad, 0, PADS[pad])
        if c.coords(pad)[1] < 0:
            c.move(pad, 0, -c.coords(pad)[1])
        elif c.coords(pad)[3] > HEIGHT:
            c.move(pad, 0, HEIGHT - c.coords(pad)[3])

def game_tick():
    if game_started:
        move_ball()
        move_pads()
        match_window.after(40, game_tick)  # loop the tick

def movement_handler(event):
    global left_pad_speed, right_pad_speed
    if event.keysym == "r":
        left_pad_speed = -PAD_SPEED
    elif event.keysym == "f":
        left_pad_speed = PAD_SPEED
    elif event.keysym == "Up":
        right_pad_speed = -PAD_SPEED
    elif event.keysym == "Down":
        right_pad_speed = PAD_SPEED

def stop_pad(event):
    global left_pad_speed, right_pad_speed
    if event.keysym in "rf":
        left_pad_speed = 0
    elif event.keysym in ("Up", "Down"):
        right_pad_speed = 0

c.focus_set()
c.bind("<KeyPress>", movement_handler)
c.bind("<KeyRelease>", stop_pad)


app_root.mainloop()

