#ifndef INPUT_H
#define INPUT_H

#include <SFML/Graphics.hpp>
#include <set>


class Input
{
 public:
    using KeyCodeType = int;
    static bool checkIfKeyPressed(KeyCodeType key);
    static bool checkIfKeyDown(KeyCodeType key);

    static void registerKeyPressed(KeyCodeType);
    static void resetKeyPressed(KeyCodeType);
    static void reset();

    static std::set<KeyCodeType> keysPressed;
    static std::set<KeyCodeType> keysPressedThisFrame;

};




class KeyCodes
{
public:
    enum
    {
        H = sf::Keyboard::Key::H,
        U = sf::Keyboard::Key::U,
        J = sf::Keyboard::Key::J,
        N = sf::Keyboard::Key::N,
        Space = sf::Keyboard::Key::Space,
        Escape = sf::Keyboard::Key::Escape

    };
};

#endif // INPUT_H
