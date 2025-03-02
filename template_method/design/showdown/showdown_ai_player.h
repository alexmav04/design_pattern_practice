#ifndef SHOWDOWN_AI_PLAYER_H
#define SHOWDOWN_AI_PLAYER_H

#include <memory>
#include "showdown_player.h"

class ShowdownAIPlayer : public ShowdownPlayer 
{
public:
    ShowdownAIPlayer();

    std::unique_ptr<Card> show() override;
};
#endif // SHOWDOWN_AI_PLAYER_H