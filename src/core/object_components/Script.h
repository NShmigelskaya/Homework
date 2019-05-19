#ifndef SCRIPT_H
#define SCRIPT_H

#include "../storage/GameObject.h"
#include "GameObjectComponent.h" 

namespace engine
{
   class Script: public GameObjectComponent
    {
    public:
        virtual void update() = 0;
        virtual void start() = 0;
        virtual void collide() = 0;
        
        Script()
        {
        }

        ~Script()
        {
        }

        virtual void onCollision(GameObject* other)
        {
        }
    };
}
#endif
