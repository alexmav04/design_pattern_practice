#include "uno_human_player.h"
#include <iostream>
#include <limits>

std::unique_ptr<Card> UnoHumanPlayer::playCard(const Card& topCard) {
    std::vector<int> validIndices;
    for (size_t i = 0; i < hands_.size(); ++i) {
        if (hands_[i]->canBePlayed(topCard)) {
            validIndices.push_back(i);
        }
    }

    if (validIndices.empty()) {
        std::cout << "No playable cards. Drawing a card...\n";
        return nullptr;
    }

    std::cout << "Playable card indices: ";
    for (int idx : validIndices) {
        std::cout << idx << " ";
    }
    std::cout << "\n";

    int choice;
    while (true) {
        std::cout << "Choose a card index to play: ";
        std::cin >> choice;

        if (!std::cin) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Try again.\n";
            continue;
        }

        if (choice == -1) {
            return nullptr;
        }

        if (std::find(validIndices.begin(), validIndices.end(), choice) != validIndices.end()) {
            std::unique_ptr<Card> playedCard = std::move(hands_[choice]);
            hands_.erase(hands_.begin() + choice);
            return playedCard;
        }
        std::cout << "Invalid choice. Try again.\n";
    }
}
