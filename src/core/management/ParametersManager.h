#ifndef PARAMETERS_MANAGER_H
#define PARAMETERS_MANAGER_H

#include <vector>

#include "../object_components/BoxCollider.h"
#include "../object_components/ParametersBody.h"

namespace engine
{   
    class ParametersManager
    {
    public:
        void update();

        void registerCollider(BoxCollider* collider);
        void unregisterCollider(BoxCollider* collider);

        void registerParametersBody(ParametersBody* rigidBody);
        void unregisterParametersBody(ParametersBody* rigidBody);

    private:
        std::vector<BoxCollider*> colliders;
        std::vector<ParametersBody*> parametersBodies;

        void updatePositions();
        void detectCollisions();

        bool isCollision(BoxCollider* first, BoxCollider* second);
        void resolveCollision(BoxCollider* first, BoxCollider* second);
    };
}

#endif  
