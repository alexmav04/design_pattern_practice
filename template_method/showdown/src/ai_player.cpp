#include "ai_player.h"

AIPlayer::AIPlayer() { }

Card AIPlayer::show() {
    if (hands_.empty()) {
        throw std::runtime_error("No card to show");
    }

    int index = std::rand() % hands_.size();
    Card card = hands_[index];
    hands_.erase(hands_.begin() + index);
    return card;
}