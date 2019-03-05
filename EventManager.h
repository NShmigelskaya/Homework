#ifndef EVENTMANAGER_H
#define EVENTMANAGER_H

#include "DataStorage.h"

struct EventManager
{
    DataStorage* DS;

    int i = 0;
    sf::Event event;

    void KeyPressed();
    void EventCatcher();
};

#endif // EVENTMANAGER_H
