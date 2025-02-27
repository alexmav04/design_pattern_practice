#include "card.h"

Card::Card(Color color, int number) 
    : color_(color), number_(number) 
{

}

int Card::number() const {
    return number_;
}

std::string Card::toString() const {
    std::string colors[] = { "Blue", "Red", "Yellow", "Green" };
    return colors[static_cast<int>(color_)] + " / " + std::to_string(number_);
}

bool Card::canBePlayed(const Card& card) const {
    return color_ == card.color_ || number_ == card.number_;
}