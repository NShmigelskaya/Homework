#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <string>
#include "DrawManager.h"
#include "EventManager.h"
#include "DataStorage.h"


class Application
{
    public:
        DrawManager drawManager;
        EventManager eventManager;
        DataStorage dataStorage;
        static Application* instance();
    private:
        static Application* m_instance;

};
