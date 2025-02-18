#include "player.h"
#include <stdexcept>
#include <algorithm>

Player::Player() 
    : name_(""), points_(0)
{

}

void Player::nameHimself() {
    std::cout << "Enter player name: ";
    std::cin >> name_;
}

void Player::drawCard(Deck& deck) {
    hands_.push_back(deck.drawCard());
}

Card Player::show() {
    if (hands_.empty()) {
        throw std::runtime_error("No cards to play!");
    }

    int index;
    while (true) {
        std::cout << name_ << " choose a card to play: (enter 0-" << hands_.size() - 1 << "): ";
        std::cin >> index;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input! Please enter a number between 0 and " << hands_.size() - 1 << ".\n";
            continue;
        }
        if (index >= 0 && index < static_cast<int>(hands_.size())) {
            break;
        }
        std::cout << "Invalid index! Please enter a number between 0 and " << hands_.size() - 1 << ".\n";
    }

    Card chosenCard = hands_[index];
    hands_.erase(hands_.begin() + index);
    return chosenCard;
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