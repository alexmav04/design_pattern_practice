#ifndef GAME_H
#define GAME_H

#include "player.h"
#include "deck.h"
#include <map>

class Game 
{
public:
    Game();

    void start();

    void takeTurn();

    void revertHands();

    void determineWinner();

private:
    std::vector<std::unique_ptr<Player>> players_;
    std::unique_ptr<Deck> deck_;
    int round_ = 1;
    std::map<int, std::vector<std::pair<int, int>>> exchangeHistory_; // <round, vector<<playerIndex, exchangePlayerIndex>>>
};

#endif // GAME_H