#include "RenderManager.h"
#include "../instruments/Camera.h"

namespace engine
{
    
    RenderManager::RenderManager(int width,int height,std::string name)
    {
        
        renderWindow = new sf::RenderWindow(sf::VideoMode(width,height), name);
        
        
    }

    sf::Vector2f getViewportSize()
    {
        return renderWindow.getSize();
    }

    sf::RenderWindow getWindow()
    {
        return window;
    }
    
    
    void RenderManager::renderObject(sf::Drawable& object)
    {
        
        renderWindow.draw(object);
        
    }
    
    
    void RenderManager::renderDrawableObjects() 
    {
        
        renderWindow.clear();
        
        for (auto renderer : renderers)
        {
            
            renderer->draw(window);  
            
        }
        
        window.display();
        
        
        
    }
    
    void RenderManager::renderColliderBorders(BoxCollider* collider)
    {
        
        sf::Vertex lines[] = 
            {
                sf::Vertex(sf::Vector2f(collider->leftTop.x, collider->leftTop.y)),
                sf::Vertex(sf::Vector2f(collider->leftTop.x, collider->rightDown.y)),

                sf::Vertex(sf::Vector2f(collider->leftTop.x, collider->leftTop.y)),
                sf::Vertex(sf::Vector2f(collider->rightDown.x, collider->leftTop.y)),

                sf::Vertex(sf::Vector2f(collider->rightDown.x, collider->leftTop.y)),
                sf::Vertex(sf::Vector2f(collider->rightDown.x, collider->rightDown.y)),

                sf::Vertex(sf::Vector2f(collider->leftTop.x, collider->rightDown.y)),
                sf::Vertex(sf::Vector2f(collider->rightDown.x, collider->rightDown.y)),
            };
            
        for (auto& line : lines)
            line.position = Camera::projectionToCamera(line.position + collider->object->position);

        renderWindow.draw(lines, 8 , sf::Lines);
            
        
    }   
    
    void RenderManager::registerRenderer(Renderer2D* renderer)
    {
        renderers.push_back(renderer);
    }

    void RenderManager::unregisterRenderer(Renderer2D* renderer)
    {
        renderers.erase(remove(renderers.begin(), renderers.end(), renderer), renderers.end());
    }

    void RenderManager::registerCollider(BoxCollider* collider)
    {
        colliders.push_back(collider);
    }

    void RenderManager::unregisterCollider(BoxCollider* collider)
    {
        colliders.erase(remove(colliders.begin(), colliders.end(), collider), colliders.end());
    }
    
}
