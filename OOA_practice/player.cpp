#include "player.h"

Player::Player() : points_(0)
{

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

std::vector<Card>& Player::hands() {
    return hands_;
}

bool Player::hasExchanged() const {
    return hasExchanged_;
}

void Player::changeExchangedStatus() {
    hasExchanged_ = !hasExchanged_;
}