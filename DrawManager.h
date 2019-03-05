#ifndef DRAWMANAGER_H
#define DRAWMANAGER_H




#include <string>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "DataStorage.h"

class DrawManager
{
    public:
        ~DrawManager();
        DataStorage* DS;
        void init();
        void destroy();
        void draw();
        void SetText(std::string s);

};

#endif // DRAWMANAGER_H
