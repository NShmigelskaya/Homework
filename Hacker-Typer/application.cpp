#include "application.h"
#include <unistd.h>


Application* Application::instance()
{
    if (!m_instance)
    {
        m_instance = new Application();
    }
    return m_instance;
}


Application* Application::m_instance = 0;

int main()
{
    Application app;
    app.drawManager.DS = &app.dataStorage;
    app.eventManager.DS = &app.dataStorage;

    app.dataStorage.text.filename = "hackcode.txt";
    app.dataStorage.text.readFromFile();
    sf::Event event;
    app.drawManager.init();

    while((app.dataStorage.window).isOpen())
    {
        while((app.dataStorage.window).pollEvent(event))
        {
            app.eventManager.event = event;
            app.eventManager.EventCatcher();
        }

        app.drawManager.draw();
        usleep(50000);
    }
    return 0;
}

