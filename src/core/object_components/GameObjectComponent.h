#ifndef GAME_OBJECT_COMPONENT_H
#define GAME_OBJECT_COMPONENT_H
#include <string> 
#include "../storage/GameObject.h"


namespace engine
{
    class GameObject;

    class GameObjectComponent
    {
    public:
        GameObjectComponent();
        std::string name = "";
        GameObject* object = 0;

    };
}
#endif
