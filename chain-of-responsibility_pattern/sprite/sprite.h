#ifndef SPRITE_H
#define SPRITE_H

#include <string>

class Sprite
{
public:
    explicit Sprite(char name) : name_(name), position_(-1) {}
    virtual ~Sprite() = default;

    std::string name() const {
        return std::string(1, name_);
    }

    int position() const {
        return position_;
    }

    void moveTo(int position) {
        position_ = position;
    }

protected:
    char name_;
    int position_;
};

#endif // SPRITE_H