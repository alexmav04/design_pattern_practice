#ifndef HUMAN_PLAYER_H
#define HUMAN_PLAYER_H

#include <vector>
#include "player.h"

class HumanPlayer : public Player {
public:
    HumanPlayer();

    Card playCard(const Card& topCard) override;
};

#endif //HUMAN_PLAYER_H