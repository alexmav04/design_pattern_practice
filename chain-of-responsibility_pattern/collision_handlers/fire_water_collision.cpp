#include "fire_water_collision.h"
#include "sprite/fire.h"
#include "sprite/water.h"
#include <iostream>

void FireWaterCollisionHandler::handle(std::unique_ptr<Sprite>& sprite1, std::unique_ptr<Sprite>& sprite2, World& world) {
    Fire* fire = dynamic_cast<Fire*>(sprite1.get()) ? dynamic_cast<Fire*>(sprite1.get()) : dynamic_cast<Fire*>(sprite2.get());
    Water* water = dynamic_cast<Water*>(sprite1.get()) ? dynamic_cast<Water*>(sprite1.get()) : dynamic_cast<Water*>(sprite2.get());

    if (fire && water) {
        std::cout << "Fire-Water collision detected. Fire and Water are removed." << std::endl;
        sprite1.reset();
        sprite2.reset();
        return;
    }
    CollisionHandler::handle(sprite1, sprite2, world);
}