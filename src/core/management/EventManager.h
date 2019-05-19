#ifndef EVENT_MANAGER_H
#define EVENT_MANAGER_H

#include <SFML/Graphics.hpp>
#include <list>
#include <vector>

namespace engine
{
    class EventManager
    {
     public:
        void pollEvents();
        void clearEvents();

        std::vector<sf::Event> getAllEventsOfType(sf::Event::EventType);

     private:
        std::list<sf::Event> newEventsPerFrame;
    };
}

#endif 
