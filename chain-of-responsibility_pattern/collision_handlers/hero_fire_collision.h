#ifndef HERO_FIRE_COLLISION_HANDLER_H
#define HERO_FIRE_COLLISION_HANDLER_H

#include "collision_handler.h"

class HeroFireCollisionHandler : public CollisionHandler
{
public:
    HeroFireCollisionHandler(std::unique_ptr<CollisionHandler> next = nullptr)
        : CollisionHandler(std::move(next)) {}
    
    void handle(std::unique_ptr<Sprite>& sprite1, std::unique_ptr<Sprite>& sprite2, World& world) override;

protected:
    std::unique_ptr<CollisionHandler> next_;   
};

#endif // HERO_FIRE_COLLISION_HANDLER_H