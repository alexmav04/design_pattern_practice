#ifndef FIRE_H
#define FIRE_H

#include "sprite.h"

class Fire : public Sprite
{
public:
    explicit Fire() : Sprite('F') { }
};

#endif // FIRE_H