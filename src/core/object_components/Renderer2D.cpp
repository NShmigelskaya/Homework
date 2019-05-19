#include <iostream>

#include "Renderer2D.h"
#include "../Engine.h"

namespace engine
{   
    void Renderer2D::setSprite(const sf::Texture& t_texture)
    {
        texture = t_texture;
        sprite.setTexture(texture);
    }

    void Renderer2D::setTexture(const sf::Texture& t_texture)
    {
        setSprite(t_texture);
    }

    void Renderer2D::draw()
    {
        auto textureSize = texture.getSize();
        sf::Vector2f newPosition = Camera::projectionToCamera(object->position - sf::Vector2f((float)textureSize.x / 2, -(float)textureSize.y / 2));

        sprite.setPosition(newPosition);
        Engine::instance()->renderManager->renderObject(sprite);
    }

    sf::Texture& Renderer2D::getTexture()
    {
        return texture;
    }
} 
