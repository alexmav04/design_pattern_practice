#include "player.h"

void Player::nameHimself() {
    std::cout << "Enter player name: ";
    std::cin >> name_;
}

std::string Player::name() const {
    return name_; 
}

void Player::drawCard(std::unique_ptr<Card> card) {
    hands_.push_back(std::move(card));
}

bool Player::hasPlayableCard(const Card& topCard) const { 
    return false; 
}

bool Player::emptyHand() const { 
    return hands_.empty(); 
}

void Player::addPoint() { 
    points_++; 
}

int Player::points() const { 
    return points_; 
}