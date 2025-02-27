#ifndef GAME_H
#define GAME_H

#include <vector>
#include "player.h"
#include "deck.h"

class Game {
public:
    Game();
    
    void start();
    void flipTop();
    void playGame();

private:
    Deck deck_;
    std::vector<Player*> players_;
    Card topCard_;
    std::vector<Card> discardCards_;

    void reshuffleDeck();
};

#endif //GAME_H