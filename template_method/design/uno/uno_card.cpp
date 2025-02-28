#include "uno_card.h"

UnoCard::UnoCard(Color color, int number)
    : color_(color), number_(number) 
{

}

std::string UnoCard::toString() const {
    std::string colors[] = {"Blue", "Red", "Yellow", "Green"};
    return colors[static_cast<int>(color_)] + " / " + std::to_string(number_);
}

bool UnoCard::operator>(const Card& card) const {
    const UnoCard& other = dynamic_cast<const UnoCard&>(card);
    return number_ > other.number_;
}

bool UnoCard::operator<(const Card& card) const {
    const UnoCard& other = dynamic_cast<const UnoCard&>(card);
    return number_ < other.number_;
}

bool UnoCard::canBePlayed(const Card& topCard) const {
    const UnoCard& other = dynamic_cast<const UnoCard&>(topCard);
    return color_ == other.color_ || number_ == other.number_;
}

Color UnoCard::color() const { 
    return color_; 
}

int UnoCard::number() const { 
    return number_; 
}