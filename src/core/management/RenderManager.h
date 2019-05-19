#ifndef RENDER_MANAGER_H
#define RENDER_MANAGER_H

#include <SFML/Graphics.hpp>
#include "../object_components/Renderer2D.h"
#include "../object_components/BoxCollider.h"

namespace engine
{   
    class RenderManager
    {
    public:
        RenderManager(int width,int height,std::string name);
        ~RenderManager();

        sf::Vector2f getViewportSize();
        sf::RenderWindow* getWindow();

        void renderDrawableObjects();
        void renderObject(sf::Drawable& object);

        void registerRenderer(Renderer2D* renderer);
        void unregisterRenderer(Renderer2D* renderer);

        void registerCollider(BoxCollider* collider);
        void unregisterCollider(BoxCollider* collider);

    private:
        std::vector<Renderer2D*> renderers;
        std::vector<BoxCollider*> colliders;
        sf::RenderWindow* renderWindow;

        void renderColliderBorders(BoxCollider* collider);
    };
}

#endif
