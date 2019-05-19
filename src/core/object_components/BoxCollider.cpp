#include "BoxCollider.h"

#include "../Engine.h"

namespace engine
{
    BoxCollider::BoxCollider()
    {
    }

    void BoxCollider::setCollider(float x1, float y1, float x2, float y2)
    {
        leftTop.x = x1;
        leftTop.y = y1;

        rightDown.x = x2;
        rightDown.y = y2;
    }

    void BoxCollider::setColliderBySprite()
    {
        if (!object->hasComponent<Renderer2D>())
            return;

        auto textureSize = object->getComponent<Renderer2D>()->getTexture().getSize();

        leftTop.x = 0 - textureSize.x / 2.0;
        leftTop.y = 0 + textureSize.y / 2.0;

        rightDown.x = 0 + textureSize.x / 2.0;
        rightDown.y = 0 - textureSize.y / 2.0;
    }
}
