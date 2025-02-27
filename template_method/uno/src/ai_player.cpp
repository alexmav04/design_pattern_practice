#include "ai_player.h"
#include <random>

AIPlayer::AIPlayer() { }

Card AIPlayer::playCard(const Card& topCard) {
    std::cout << "\n" << name_ << "'s turn\n";
    std::cout << "Top card: " << topCard.toString() << "\n";

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

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, validIndices.size() - 1);
    int choice = validIndices[dist(gen)];

    Card playedCard = hands_[choice];
    hands_.erase(hands_.begin() + choice);
    return playedCard;
}