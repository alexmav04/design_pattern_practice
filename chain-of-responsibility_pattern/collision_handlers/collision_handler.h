#ifndef COLLISION_HANDLER_H
#define COLLISION_HANDLER_H

#include <memory>
#include "sprite.h"
#include "world.h"

class CollisionHandler
{
public:
    explicit CollisionHandler(std::unique_ptr<CollisionHandler> next = nullptr);

    virtual void handle(std::unique_ptr<Sprite>& sprite1, std::unique_ptr<Sprite>& sprite2, World& world) = 0;

protected:
    std::unique_ptr<CollisionHandler> next_;   
};

#endif // COLLISION_HANDLER_H