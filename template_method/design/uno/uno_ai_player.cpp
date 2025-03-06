#include "uno_ai_player.h"
#include <iostream>

std::unique_ptr<Card> UnoAIPlayer::playCard(const Card& topCard) {
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

    static std::mt19937 gen(std::random_device{}());
    std::uniform_int_distribution<> dist(0, validIndices.size() - 1);
    int choice = validIndices[dist(gen)];

    std::unique_ptr<Card> playedCard = std::move(hands_[choice]);
    hands_.erase(hands_.begin() + choice);
    return playedCard;
}
