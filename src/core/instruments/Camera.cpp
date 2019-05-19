#include "Camera.h"
#include "../Engine.h"

namespace engine
{
    sf::Vector2f Camera::projectionToCamera(sf::Vector2f objectPosition)
    {
        sf::Vector2f windowSize = Engine::instance()->renderManager->getViewportSize();
        
        return sf::Vector2f(objectPosition.x + position.x + windowSize.x / 2, -objectPosition.y + position.y + windowSize.y / 2);
    }
}
