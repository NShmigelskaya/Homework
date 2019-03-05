#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "DrawManager.h"


void DrawManager::draw() {
    this->DS->text.text.setString(this->DS->text.currentText);
    sf::FloatRect textBounds = this->DS->text.text.getGlobalBounds();
    if(textBounds.height > 600) {
        this->DS->text.text.setPosition(0, 600 - textBounds.height);
    }
    DS->window.clear();
    DS->window.draw(this->DS->texture.sprite);
    DS->window.draw(this->DS->text.text);
    DS->window.display();
}

void DrawManager::destroy(){
    DS->window.close();
}

DrawManager::~DrawManager(){
    this->DS->window.close();
}
void DrawManager::init(){
    this->DS->window.create(sf::VideoMode(800,612),"H-Tp");
    this->DS->texture.texture.loadFromFile("logo1.jpg");
    this->DS->texture.sprite.setTexture(this->DS->texture.texture);
    this->DS->text.font.loadFromFile("arial.ttf");
    this->DS->text.text.setFillColor(sf::Color::Green);
    this->DS->text.text.setFont(this->DS->text.font);
}
