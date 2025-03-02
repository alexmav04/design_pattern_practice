#ifndef SHOWDOWN_HUMAN_PLAYER_H
#define SHOWDOWN_HUMAN_PLAYER_H

#include "../player.h"

class ShowdownHumanPlayer : public Player 
{
public:
    ShowdownHumanPlayer();

    std::unique_ptr<Card> show() override;
    std::unique_ptr<Card> playCard(const Card& topCard) override;
};

#endif // SHOWDOWN_HUMAN_PLAYER_H