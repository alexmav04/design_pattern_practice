#ifndef HUMAN_PLAYER_H
#define HUMAN_PLAYER_H

#include "player.h"

class HumanPlayer : public Player
{
public:
    HumanPlayer();

    void nameHimself() override;

    bool wantExchange() override;

    int chooseExchangePlayer() override;

    Card show() override;
};

#endif //HUMAN_PLAYER_H