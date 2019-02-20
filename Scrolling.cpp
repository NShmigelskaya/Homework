#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "drawManager.cpp"



struct EventMeneger
{
    std::string text;
    std::string s;
    int i = 0;
    sf::Event event;

    void KeyPressed()
    {
        for (int k = 1; k < 4; k++)
        {
            s = s + text[i];
            i++;
        }
    };

    void EventCatcher()
    {
        if (event.type == sf::Event::KeyPressed){
            KeyPressed();
            }        
    }
};