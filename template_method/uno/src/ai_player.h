#ifndef AI_PLAYER_H
#define AI_PLAYER_H

#include <vector>
#include "player.h"

class AIPlayer : public Player {
public:
    AIPlayer();

    Card playCard(const Card& topCard) override;
};

#endif //AI_PLAYER_H