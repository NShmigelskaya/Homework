#pragma once

#include <string>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class DrawManager
{
    public:
        ~DrawManager();
        void init();
        void destroy();
        void draw();
        void SetText(std::string s);
	sf::RenderWindow* window = NULL;
    private:
        sf::Font font;
        sf::Sprite* bg = NULL;
        sf::Text* text = NULL;
    
};
