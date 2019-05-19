#ifndef LOGICS_MANAGER_H
#define LOGICS_MANAGER_H

#include <vector>
#include <list>
#include <map>

#include "../storage/GameObject.h"
#include "EventManager.h"

namespace engine
{   
    class LogicsManager
    {
    public:
        void updateLogics();
        void callStartForScripts();
        void callUpdateForScripts();
        void callOnCollisionForObject(GameObject* object, GameObject* other);

        void registerScript(Script* script);
        void unregisterScript(Script* script);

        EventManager eventManager;
    private:
        std::list<Script*> notStartedScripts;
        std::vector<Script*> scripts; 
    };
}

#endif 
 
