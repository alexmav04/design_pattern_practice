#include "hero_fire_collision.h"
#include "sprite/hero.h"
#include "sprite/fire.h"
#include <iostream>

void HeroFireCollisionHandler::handle(std::unique_ptr<Sprite>& sprite1, std::unique_ptr<Sprite>& sprite2, World& world) {
    Hero* hero = dynamic_cast<Hero*>(sprite1.get()) ? dynamic_cast<Hero*>(sprite1.get()) : dynamic_cast<Hero*>(sprite2.get());
    Fire* fire = dynamic_cast<Fire*>(sprite1.get()) ? dynamic_cast<Fire*>(sprite1.get()) : dynamic_cast<Fire*>(sprite2.get());

    if (hero && fire) {
        hero->modifyHp(-10);
        std::cout << "Hero-Fire collision detected. Hero's HP decreased by 10. Hero's HP: " << hero->hp() << std::endl;
        world.removeSprite(fire->position());

        if (!hero->isAlive()) {
            std::cout << "Hero is dead." << std::endl;
            world.removeSprite(hero->position());
        }
        return;
    }
    CollisionHandler::handle(sprite1, sprite2, world);
}