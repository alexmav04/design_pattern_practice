#ifndef WORLD_H
#define WORLD_H

#include "sprite/sprite.h"
#include <memory>
#include <vector>

class World
{
public:
    World();

    void start();

    bool moveSprite(int x1, int x2);

    std::unique_ptr<Sprite>& getSpriteByPos(int pos);

    void removeSprite(int pos);

    void setSprite(int pos, std::unique_ptr<Sprite> sprite);

    bool isOccupied(int pos) const;

    bool isValidPos(int pos) const;

    void print() const;

private:
    static const int MAX_LENGTH = 30;
    int length_;
    std::vector<std::unique_ptr<Sprite>> sprites_;
};

#endif // WORLD_H