#ifndef CAMERA_H
#define CAMERA_H

#include <SFML/Graphics.hpp>

namespace engine
{
    class Camera
    {
     public:
        static sf::Vector2f projectionToCamera(sf::Vector2f objectPosition);

     private:
        Camera();

        static sf::Vector2f position;
    };
}

#endif
