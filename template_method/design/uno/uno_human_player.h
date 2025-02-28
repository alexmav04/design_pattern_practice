#ifndef UNO_HUMAN_PLAYER_H
#define UNO_HUMAN_PLAYER_H

#include "../player.h"
#include "uno_card.h"

class UnoHumanPlayer : public Player {
public:
    std::unique_ptr<Card> playCard(const Card& topCard) override;
    std::unique_ptr<Card> show() override {
        return nullptr;
    }
};

#endif // UNO_HUMAN_PLAYER_H
