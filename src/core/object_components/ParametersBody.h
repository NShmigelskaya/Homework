#ifndef PARAMETERSBODY_H
#define PARAMETERSBODY_H
#include "GameObjectComponent.h"
#include "SFML/Graphics.hpp"
 

namespace engine
{
    class ParametersBody : public GameObjectComponent
    {
    public:
        ParametersBody();
        sf::Vector2f gravitationVal = sf::Vector2f(0,10);
        float mass = 1.0f;

        sf::Vector2f velocity;
        sf::Vector2f acceleration;
        sf::Vector2f prevPosition;
        
    };
}
#endif
