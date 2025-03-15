#include "hero_water_collision.h"
#include "sprite/hero.h"
#include "sprite/water.h"
#include <iostream>

void HeroWaterCollisionHandler::handle(std::unique_ptr<Sprite>& sprite1, std::unique_ptr<Sprite>& sprite2, World& world) {
    Hero* hero = dynamic_cast<Hero*>(sprite1.get()) ? dynamic_cast<Hero*>(sprite1.get()) : dynamic_cast<Hero*>(sprite2.get());
    Water* water = dynamic_cast<Water*>(sprite1.get()) ? dynamic_cast<Water*>(sprite1.get()) : dynamic_cast<Water*>(sprite2.get());

    if (hero && water) {
        hero->modifyHp(10);
        std::cout << "Hero-Water collision detected. Hero's HP increased by 10. Hero's HP: " << hero->hp() << std::endl;
        sprite1.get() == water ? sprite1.reset() : sprite2.reset();
        return;
    }
    CollisionHandler::handle(sprite1, sprite2, world);
}
