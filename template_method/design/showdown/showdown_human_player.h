#ifndef SHOWDOWN_HUMAN_PLAYER_H
#define SHOWDOWN_HUMAN_PLAYER_H

#include "showdown_player.h"

class ShowdownHumanPlayer : public ShowdownPlayer 
{
public:
    ShowdownHumanPlayer();

    std::unique_ptr<Card> show() override;
};

#endif // SHOWDOWN_HUMAN_PLAYER_H