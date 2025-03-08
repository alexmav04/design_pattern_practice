#ifndef AI_PLAYER_H
#define AI_PLAYER_H

#include "player.h"

class AIPlayer : public Player
{
public:
    AIPlayer();

    void nameHimself() override;

    bool wantExchange() override;

    int chooseExchangePlayer() override;

    Card show() override;

private:
    std::string generateRandomName();
};

#endif //AI_PLAYER_H