#include "EventManager.h"
#include "DataStorage.h"

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>


void EventManager::KeyPressed()
{
    for (int k = 1; k < 4; k++)
    {
        this->DS->text.currentText += this->DS->text.fullText[i];
        i++;
    }
}

void EventManager::EventCatcher()
{
    while((DS->window).pollEvent(event))
    {
        if (event.type == sf::Event::KeyPressed){
            KeyPressed();
            };
        if (event.type == sf::Event::Closed)
        {
            (DS->window).close();
        };
    };
}
