#include "human_player.h"
#include <iostream>
#include <algorithm>

HumanPlayer::HumanPlayer() { }

Card HumanPlayer::show() {
    if (hands_.empty()) {
        throw std::runtime_error("No cards to play!");
    }

    int index;
    while (true) {
        std::string range = (hands_.size() == 1) ? "0" : "0-" + std::to_string(hands_.size() - 1);
        std::cout << name_ << " choose a card to play: (enter " << range << "): ";
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