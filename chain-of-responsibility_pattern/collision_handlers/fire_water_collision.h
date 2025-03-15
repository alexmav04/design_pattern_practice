#ifndef FIRE_WATER_COLLISION_HANDLER_H
#define FIRE_WATER_COLLISION_HANDLER_H

#include "collision_handler.h"

class FireWaterCollisionHandler : public CollisionHandler
{
public:
    FireWaterCollisionHandler(std::unique_ptr<CollisionHandler> next = nullptr)
        : CollisionHandler(std::move(next)) {}
    
    void handle(std::unique_ptr<Sprite>& sprite1, std::unique_ptr<Sprite>& sprite2, World& world) override;
};

#endif // FIRE_WATER_COLLISION_HANDLER_H