#ifndef HERO_H
#define HERO_H

#include "sprite.h"

class Hero : public Sprite
{
public:
    explicit Hero() : Sprite('H') {
        hp_ = 30;
    }

    void modifyHp(int hp) {
        hp_ += hp;
    }

    bool isAlive() const {
        return hp_ > 0;
    }

    int hp() const {
        return hp_;
    }

private:
    int hp_;
};

#endif // HERO_H