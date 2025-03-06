#ifndef SHOWDOWN_GAME_H
#define SHOWDOWN_GAME_H

#include <vector>
#include "../game.h"

class ShowdownGame : public Game 
{
public:
    ShowdownGame();

    std::unique_ptr<Player> createHumanPlayer();

    std::unique_ptr<Player> createAIPlayer();

    int initialCardCount() const override;

    void takeATurn() override;

    bool isGameOver() const override;

    void determineWinner() override;

    void revealAll(const std::vector<std::pair<Player*, std::unique_ptr<Card>>>& cards);

private:
    int currentRound_ = 0;
};

#endif // SHOWDOWN_GAME_H