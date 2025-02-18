#ifndef GAME_H
#define GAME_H

#include <vector>
#include "player.h"
#include "deck.h"

class Game {
public:
    Game();
    
    void start();
    void takeATurn();
    void revealAll(std::vector<std::pair<Player*, Card>> cards);
    void playGame();
    void determineWinner();

private:
    Deck deck_;
    std::vector<Player*> players_;
};

#endif //GAME_H