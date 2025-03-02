#ifndef SHOWDOWN_PLAYER_H
#define SHOWDOWN_PLAYER_H

#include "../player.h"

class ShowdownPlayer : public Player 
{
public:
    std::unique_ptr<Card> playCard(const Card& topCard) override {
        return nullptr;
    }
};

#endif // SHOWDOWN_PLAYER_H