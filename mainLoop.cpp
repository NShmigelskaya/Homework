#include <cstring>
#include <iostream>
#include <fstream>
#include <unistd.h>

#include "drawManager.cpp"
#include "DataStorge.cpp"
#include "Scrolling.cpp"



int main() {

    EventMeneger EM;
    DataStorage DS;
    DS.filename = "had-code.txt";
    std::string text = DS.readFromFile();
    int i = 0;
    sf::Event event;

    EM.text = text;

    DrawManager DM;

    DM.init();

    while((DM.window)->isOpen())
    {
        std::string s = EM.s;
        while((DM.window)->pollEvent(event))
        {
            EM.event = event;
            EM.EventCatcher();
            if (event.type == sf::Event::Closed){
                (DM.window)->close();
            }
        }    

        DM.SetText(s);
        DM.draw();
        usleep(50000);
    }
    return 0;
}
