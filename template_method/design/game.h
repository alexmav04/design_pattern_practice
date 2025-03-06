#ifndef GAME_H
#define GAME_H

#include "player.h"
#include "deck.h"
#include <vector>
#include <memory>
#include <iostream>
#include <algorithm>

class Game {
public:
    void start();

    void playGame();

    virtual std::unique_ptr<Player> createHumanPlayer() = 0;
    
    virtual std::unique_ptr<Player> createAIPlayer() = 0;

    void setupPlayers();
    
    virtual int initialCardCount() const = 0;

    void dealInitialCards();

    virtual void otherCardSetup() {}

    virtual void takeATurn() = 0;

    virtual bool isGameOver() const = 0;

    virtual void determineWinner() = 0;
    
protected:
    std::vector<std::unique_ptr<Player>> players_;
    std::unique_ptr<Deck> deck_;
};

#endif // GAME_H