#include "player.h"
#include <stdexcept>
#include <algorithm>

Player::Player() : name_(""), points_(0)
{

}

void Player::nameHimself() {
    std::cout << "Enter player name: ";
    std::cin >> name_;
}

void Player::drawCard(Deck& deck) {
    hands_.push_back(deck.drawCard());
}

void Player::addPoint() {
    points_++;
}

int Player::points() const {
    return points_;
}

std::string Player::name() const {
    return name_;
}