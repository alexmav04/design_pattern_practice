#include "showdown_ai_player.h"
#include <iostream>
#include <random>

ShowdownAIPlayer::ShowdownAIPlayer() 
{
    
}

std::unique_ptr<Card> ShowdownAIPlayer::playCard() {
    if (hands_.empty()) {
        std::cout << name_ << " has no cards!\n";
        return nullptr;
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, hands_.size() - 1);
    int choice = dist(gen);

    std::unique_ptr<Card> playedCard = std::move(hands_[choice]);
    hands_.erase(hands_.begin() + choice);
    return playedCard;
}