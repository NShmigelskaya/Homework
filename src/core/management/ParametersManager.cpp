#include "ParametersManager.h"

#include "../Engine.h"
#include "../instruments/Time.h"

#include <SFML/Graphics.hpp>
#include <cmath>

namespace engine
{
    
    void ParametersManager::update()
    {
        updatePositions();
        detectCollisions();
    }

    void ParametersManager::updatePositions()
    {
        for(auto& body: parametersBodies)
        {
            body->prevPosition = body->object->position;
            body->velocity += body->gravitationVal*Time::dTime;
            body->object->position+= body->velocity*Time::dTime; 

        }
    }

    void ParametersManager::detectCollisions()
    {
        for (auto collider1 : colliders)
            for (auto collider2 : colliders)
            {
                if (collider1->object->hasComponent<ParametersBody>())
                    continue;

                if (collider1 == collider2)
                    continue;

                if (isCollision(collider1, collider2))
                {
                    Engine::instance()->logicsManager->callOnCollisionForObject(collider1->object, collider2->object);
                    Engine::instance()->logicsManager->callOnCollisionForObject(collider2->object, collider1->object); 
                    resolveCollision(collider1, collider2);
                }
    
            }
    }
    
    bool ParametersManager::isCollision(BoxCollider* first, BoxCollider* second)
    {
        
        sf::Vector2f leftTop1 = first->object->position + first->leftTop;
        sf::Vector2f leftTop2 = second->object->position + second->leftTop;
        sf::Vector2f rightDown1 = first->object->position + first->rightDown;
        sf::Vector2f rightDown2 = second->object->position + second->rightDown;       
        
        if (rightDown1.x < leftTop2.x)
            return false;

        if (leftTop1.x > rightDown2.x)
            return false;

        if (rightDown1.y > leftTop2.y)
            return false;

        if (leftTop1.y < rightDown2.y)
            return false;

        return true;        
    }
    
    void ParametersManager::resolveCollision(BoxCollider* first, BoxCollider* second)
    {
        GameObject* moving;
        if(first->object->getComponent<ParametersBody>()->velocity != sf::Vector2f())
            moving = first->object;
        else
            moving = second->object;

        ParametersBody* movingBody = moving->getComponent<ParametersBody>();

        auto v = moving->position - movingBody->prevPosition;
        float v_len = sqrt(v.x*v.x + v.y*v.y);
        auto trajectory = v / v_len;

        while(isCollision(first, second)) 
            moving->position -= trajectory;

        movingBody->velocity = sf::Vector2f();
    }

    
    void ParametersManager::registerCollider(BoxCollider* collider)
    {
        colliders.push_back(collider);
    }

    void ParametersManager::unregisterCollider(BoxCollider* collider)
    {
        colliders.erase(remove(colliders.begin(), colliders.end(), collider), colliders.end());
    }

    void ParametersManager::registerParametersBody(ParametersBody* parametersBody)
    {
        parametersBodies.push_back(parametersBody);
    }

    void ParametersManager::unregisterParametersBody(ParametersBody* parametersBody)
    {
        parametersBodies.erase(remove(parametersBodies.begin(), parametersBodies.end(), parametersBody), parametersBodies.end());
    }
    
} 
