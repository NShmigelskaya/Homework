#include "../Engine.h"
#include "EventManager.h"
#include "../storage/DataStorage.h"

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>


namespace engine
{
    void EventManager::pollEvents()
    {
        sf::Event event;
        auto window = Engine::instance()->renderManager->getWindow();

        while(window->pollEvent(event))
        {
            switch(event.type)
            {
                case sf::Event::KeyPressed:
                    Input::registerKeyPressed(event.key.code);
                    break;
                case sf::Event::KeyReleased:
                    Input::resetKeyPressed(event.key.code);
                    break;
                case sf::Event::Closed:
                    window->close();
                default:
                    break;

                newEventsPerFrame.push_back(event);

            }
        }

    }

    void EventManager::clearEvents()
    {
        newEventsPerFrame.clear();
    }

    std::vector<sf::Event> EventManager::getAllEventsOfType(sf::Event::EventType type)
    {
        std::vector<sf::Event> eventsOfType;

        for (auto& event : newEventsPerFrame)
            if (event.type == type)
                eventsOfType.push_back(event);

        return eventsOfType;
    }
}
