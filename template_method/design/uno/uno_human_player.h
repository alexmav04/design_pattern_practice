#ifndef UNO_HUMAN_PLAYER_H
#define UNO_HUMAN_PLAYER_H

#include "uno_player.h"
#include "uno_card.h"

class UnoHumanPlayer : public UnoPlayer {
public:
    std::unique_ptr<Card> playCard(const Card& topCard) override;
};

#endif // UNO_HUMAN_PLAYER_H
