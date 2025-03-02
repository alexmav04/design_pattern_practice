#ifndef SHOWDOWN_GAME_H
#define SHOWDOWN_GAME_H

#include <vector>
#include "../game.h"

class ShowdownGame : public Game 
{
public:
    ShowdownGame();

    void setupPlayers() override;  
    void dealInitialCards() override;
    void takeATurn() override;
    int getTotalRounds() const override;
    bool isGameOver() const override;
    void determineWinner() override;
    void revealAll(const std::vector<std::pair<Player*, std::unique_ptr<Card>>>& cards);

private:
    int currentRound_ = 0;
};

#endif // SHOWDOWN_GAME_H