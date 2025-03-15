#include "world.h"
#include <iostream>
#include <ctime>
#include "sprite/hero.h"
#include "sprite/fire.h"
#include "sprite/water.h"

World::World()
    : sprites_(MAX_LENGTH)
{
    std::srand(static_cast<unsigned int>(std::time(0)));
}

void World::start() {
    for (int i = 0; i < MAX_LENGTH; i++) {
        sprites_[i].reset();
    }

    int placed = 0;
    while (placed < 10) {
        int pos = std::rand() % MAX_LENGTH;
        if (isOccupied(pos)) {
            continue;
        }
        int type = std::rand() % 3;
        switch (type) {
            case 0:
                sprites_[pos] = std::make_unique<Hero>();
                break;
            case 1:
                sprites_[pos] = std::make_unique<Fire>();
                break;
            case 2:
                sprites_[pos] = std::make_unique<Water>();
                break;
        }
        placed++;
    }
}

bool World::moveSprite(int x1, int x2) {
    if (!isValidPos(x1) || !isValidPos(x2)) {
        std::cout << "Invalid position" << std::endl;
        return false;
    }

    if (!sprites_[x1]) {
        std::cout << "No sprite at position " << x1 << std::endl;
        return false;
    }

    if (x1 == x2) {
        std::cout << "Same position" << std::endl;
        return false;
    }

    if (!sprites_[x2]) {
        sprites_[x1]->moveTo(x2);
        sprites_[x2] = std::move(sprites_[x1]);
        std::cout << "Sprite moved from " << x1 << " to " << x2 << std::endl;
        print();
        return true;
    }

    return false;
}

std::unique_ptr<Sprite>& World::getSpriteByPos(int pos) {
    static std::unique_ptr<Sprite> nullSprite = nullptr;

    if (!isValidPos(pos)) {
        std::cout << "Invalid position: " << pos << std::endl;
        return nullSprite;
    }
    if (!sprites_[pos]) {
        return nullSprite;
    }

    return sprites_[pos];
}


void World::removeSprite(int pos) {
    if (isValidPos(pos)) {
        sprites_[pos].reset();
    }
}

void World::setSprite(int pos, std::unique_ptr<Sprite> sprite) {
    if (!isValidPos(pos)) {
        return;
    }
    if (sprite) {
        sprite->moveTo(pos);
    }
    sprites_[pos] = std::move(sprite);
}

bool World::isOccupied(int pos) const {
    return isValidPos(pos) && sprites_[pos] != nullptr;
}

bool World::isValidPos(int pos) const {
    return pos >= 0 && pos < MAX_LENGTH;
}

void World::print() const {
    std::cout << "World: " << std::endl;

    std::cout << "|";
    for (int i = 0; i < MAX_LENGTH; i++) {
        std::cout << " " << (i < 10 ? " " : "") << i << " |";
    }
    std::cout << std::endl;

    std::cout << "|";
    for (int i = 0; i < MAX_LENGTH; i++) {
        if (sprites_[i]) {
            std::cout << "  " << sprites_[i]->name() << " |";
        } else {
            std::cout << "  . |";
        }
    }
    std::cout << "\n" << std::endl;
}

