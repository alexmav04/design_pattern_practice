
#include "collision_handler.h"
#include <iostream>

CollisionHandler::CollisionHandler(std::unique_ptr<CollisionHandler> next) 
    : next_(std::move(next)) 
{

}

void CollisionHandler::handle(std::unique_ptr<Sprite>& sprite1, std::unique_ptr<Sprite>& sprite2, World& world) {
    if (next_) {
        next_->handle(sprite1, sprite2, world);
    }
}
