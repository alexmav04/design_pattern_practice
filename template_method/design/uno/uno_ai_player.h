#ifndef UNO_AI_PLAYER_H
#define UNO_AI_PLAYER_H

#include "../player.h"
#include <random>

class UnoAIPlayer : public Player {
public:
    std::unique_ptr<Card> playCard(const Card& topCard) override;
    std::unique_ptr<Card> show() override {
        return nullptr;
    }
};

#endif // UNO_AI_PLAYER_H
