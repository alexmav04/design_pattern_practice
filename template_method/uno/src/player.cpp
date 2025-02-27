#include "player.h"
#include <stdexcept>
#include <algorithm>

Player::Player() : name_("")
{

}

void Player::nameHimself() {
    std::cout << "Enter player name: ";
    std::cin >> name_;
}

bool Player::hasPlayableCard(const Card& card) const {
    return std::any_of(hands_.begin(), hands_.end(), [&](const Card& c) {
        return c.canBePlayed(card);
    });
}

void Player::drawCard(Deck& deck) {
    if (!deck.isEmpty()) {
        hands_.push_back(deck.drawCard());
    }
}

bool Player::emptyHand() const {
    return hands_.empty();
}

std::string Player::name() const {
    return name_;
}