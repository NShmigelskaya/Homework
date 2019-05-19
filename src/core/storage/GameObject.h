#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <iostream>
#include <string>
#include <typeinfo>
#include <vector>
#include <SFML/Graphics.hpp>
#include "../object_components/Renderer2D.h"
#include "../object_components/Script.h"
#include "../object_components/BoxCollider.h"
#include "../object_components/GameObjectComponent.h"

namespace engine
{
    class GameObject 
    {
    public:
        GameObject();
        GameObject(std::string m_name);
        ~GameObject();
        
        sf::Vector2f position;
        std::string name;
        std::vector<GameObjectComponent*> components;
        void fixPosition(float x, float y);
        
        template <typename ComponentType>
        void addComponent();
        
        template <typename ComponentType>
        ComponentType* getComponent();

        template <typename ComponentType>
        bool hasComponent();
        
        void registerObjectScript(GameObjectComponent* script);
        void unregisterObjectScript(GameObjectComponent* script);

        void registerObjectRenderer(GameObjectComponent* renderer);
        void unregisterObjectRenderer(GameObjectComponent* renderer);

        void registerObjectBoxCollider(GameObjectComponent* collider);
        void unregisterObjectCollider(GameObjectComponent* collider);
        
    }; 
    
    
    template <typename ComponentType>
    void GameObject::addComponent()
    {
        ComponentType* component = new ComponentType;

        component->name = typeid(ComponentType).name();
        component->parentObject = this;
        components.push_back(component);

        if (std::is_base_of<Script, ComponentType>())
        {
            registerObjectScript(component.get());
        }

        if (typeid(ComponentType).name() == typeid(Renderer2D).name())
        {
            registerObjectRenderer(component.get());
        }

        if (typeid(ComponentType).name() == typeid(BoxCollider).name())
        {
            registerObjectCollider(component.get());
        }
    }
    
    
    template <typename ComponentType>
    bool GameObject::hasComponent()
    {
       for (auto component : components)
           if (component->name == typeid(ComponentType).name())
           {
               return true;
           }

       return false;
   }
    
    template <typename ComponentType>
    ComponentType* GameObject::getComponent()
    {
       for (auto component : components)
           if (component->name == typeid(ComponentType).name())
           {
               ComponentType* wired = static_cast<ComponentType*>(component);
               return wired;
           }
    }
    
}
#endif // GAMEOBJECT_H
