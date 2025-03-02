#ifndef UNO_AI_PLAYER_H
#define UNO_AI_PLAYER_H

#include "uno_player.h"
#include <random>

class UnoAIPlayer : public UnoPlayer {
public:
    std::unique_ptr<Card> playCard(const Card& topCard) override;
};

#endif // UNO_AI_PLAYER_H
