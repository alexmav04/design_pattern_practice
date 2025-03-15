#include "world.h"
#include "collision_handlers/hero_fire_collision.h"
#include "collision_handlers/hero_water_collision.h"
#include "collision_handlers/fire_water_collision.h"
#include "collision_handlers/collision_handler.h"
#include <iostream>

int main() {
    World world;
    world.start();
    world.print();

    auto collisionHandler = std::make_unique<HeroFireCollisionHandler>(
                                std::make_unique<HeroWaterCollisionHandler>(
                                    std::make_unique<FireWaterCollisionHandler>()
                                )
                            );
    
    while (true) {
        std::cout << "Enter the x1 and x2 (separated by space) to move sprite: ";
        int x1, x2;
        if (!(std::cin >> x1 >> x2)) {
            break;
        }

        std::unique_ptr<Sprite>& sprite1 = world.getSpriteByPos(x1);
        std::unique_ptr<Sprite>& sprite2 = world.getSpriteByPos(x2);

        if (!sprite1) {
            std::cout << "No sprite at position " << x1 << "\n" << std::endl;
            continue;
        }

        if (world.moveSprite(x1, x2)) {
            continue;
        }

        if (typeid(*sprite1) == typeid(*sprite2)) {
            std::cout << "Same type of sprites." << "\n" << std::endl;
            continue;;
        }

        collisionHandler->handle(sprite1, sprite2, world);

        world.setSprite(x2, std::move(sprite1));
        world.print();
    }
    return 0;
}