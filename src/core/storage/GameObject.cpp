#include <iostream>
#include <string>
#include "GameObject.h"
#include "../Engine.h"


namespace engine
{
    
    GameObject::GameObject()
    {  
        name = m_name;
    };
    
    GameObject::~GameObject()
    {
        
        for (auto component : components)
        {
             if (component->typeName == typeid(Renderer2D).name())
            {
                unregisterObjectRenderer(component.get());
                continue;
            }

            if (component->typeName == typeid(BoxCollider).name())
            {
                unregisterObjectCollider(component.get());
                continue;
            }
            
            unregisterObjectScript(component.get());
            
            
        }
        components.clear();
        
        
    };
    
    void GameObject::fixPosition(float x, float y)
    {
        
        position = {x,y}
        
    }
    
     void GameObject::registerObjectScript(GameObjectComponent* script)
    {
        Engine::instance()->logicsManager->registerScript(static_cast<Script*>(script));
    }

    void GameObject::unregisterObjectScript(GameObjectComponent* script)
    {
        Engine::instance()->logicsManager->unregisterScript(static_cast<Script*>(script));
    }

    void GameObject::registerObjectRenderer(GameObjectComponent* renderer)
    {
        Engine::instance()->renderManager->registerRenderer(static_cast<Renderer2D*>(renderer));
    }

    void GameObject::unregisterObjectRenderer(GameObjectComponent* renderer)
    {
        Engine::instance()->renderManager->unregisterRenderer(static_cast<Renderer2D*>(renderer));
    }

    void GameObject::registerObjectBoxCollider(GameObjectComponent* collider)
    {
        Engine::instance()->parametersManager->registerCollider(static_cast<BoxCollider*>(collider));
    }

    void GameObject::unregisterObjectBoxCollider(GameObjectComponent* collider)
    {
        Engine::instance()->parametersManager->unregisterCollider(static_cast<BoxCollider*>(collider));
    }
    
}
 
