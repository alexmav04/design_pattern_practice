#include "human_player.h"
#include <iostream>
#include <algorithm>

HumanPlayer::HumanPlayer() { }

Card HumanPlayer::playCard(const Card& topCard) {
    std::cout << "\n" << name_ << "'s turn\n";
    std::cout << "Top card: " << topCard.toString() << "\n";

    std::cout << "Hands:\n";
    for (size_t i = 0; i < hands_.size(); ++i) {
        std::cout << "(" << i << ") " << hands_[i].toString() << "\n";
    }

    std::vector<int> validIndices;
    for (size_t i = 0; i < hands_.size(); ++i) {
        if (hands_[i].canBePlayed(topCard)) {
            validIndices.push_back(i);
        }
    }

    if (validIndices.empty()) {
        std::cout << "No playable cards. Drawing a card...\n";
        return Card(Color::BLUE, -1);
    }

    std::cout << "Playable card indices: ";
    for (int idx : validIndices) {
        std::cout << idx << " ";
    }
    std::cout << "\n";

    int choice;
    while (true) {
        std::cout << "Choose a card index to play (-1 to draw a card): ";
        std::cin >> choice;

        if (!std::cin) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Try again.\n";
            continue;
        }

        if (choice == -1) {
            return Card(Color::BLUE, -1);
        }

        if (std::find(validIndices.begin(), validIndices.end(), choice) != validIndices.end()) {
            Card playedCard = hands_[choice];
            hands_.erase(hands_.begin() + choice);
            return playedCard;
        } else {
            std::cout << "Invalid input. Try again.\n";
        }
    }
}