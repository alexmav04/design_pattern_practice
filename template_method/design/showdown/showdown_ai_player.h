#ifndef SHOWDOWN_AI_PLAYER_H
#define SHOWDOWN_AI_PLAYER_H

#include <memory>
#include "../player.h"

class ShowdownAIPlayer : public Player 
{
public:
    ShowdownAIPlayer();

    std::unique_ptr<Card> show() override;
    std::unique_ptr<Card> playCard(const Card& topCard) override;
};
#endif // SHOWDOWN_AI_PLAYER_H