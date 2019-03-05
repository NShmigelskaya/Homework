#include <cstring>
#include <iostream>
#include <fstream>
#include <unistd.h>
#include "DataStorage.h"
#include "DrawManager.h"
#include "EventManager.h"


/*int main() {

    EventManager EM;
    DataStorage DS;
    DS.text->filename = "hackcode.txt";
    DS.text->readFromFile();
    sf::Event event;

    DrawManager DM;
    DM.DS = &DS;
    EM.DS = &DS;
    DM.init();

    while((DS.window).isOpen())
    {
        while((DS.window).pollEvent(event))
        {
            EM.event = event;
            EM.EventCatcher();
        }

        DM.draw();
        usleep(50000);
    }
    return 0;
}
*/
