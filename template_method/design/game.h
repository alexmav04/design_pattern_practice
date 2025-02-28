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
    virtual void start() {
        deck_->shuffle();
        setupPlayers();
        dealInitialCards();
    }

    virtual void playGame() {
        int i = 1;
        while (!isGameOver()) {
            std::cout << "\n==== Round " << i++ << " ====\n";
            takeATurn();
        }
        determineWinner();
    }

    virtual void setupPlayers() = 0;
    
    virtual void dealInitialCards() = 0;

    virtual void takeATurn() = 0;

    virtual int getTotalRounds() const = 0;

    virtual bool isGameOver() const = 0;

    virtual void determineWinner() {
        auto winner_it = std::max_element(players_.begin(), players_.end(),
            [](const std::unique_ptr<Player>& a, const std::unique_ptr<Player>& b) {
                return a->points() < b->points();
            });
    
        if (winner_it != players_.end()) {
            Player* winner = winner_it->get();
            std::cout << " ==== Game Over ==== \n";
            std::cout << winner->name() << " won the game with " << winner->points() << " points.\n";
        }
    }
    
protected:
    std::vector<std::unique_ptr<Player>> players_;
    std::unique_ptr<Deck> deck_;
};

#endif // GAME_H