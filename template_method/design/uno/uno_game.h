#ifndef UNO_GAME_H
#define UNO_GAME_H

#include "../game.h"
#include "uno_card.h"
#include <memory>

class UnoGame : public Game {
public:
    UnoGame();
    
    void setupPlayers() override;
    void dealInitialCards() override;
    void takeATurn() override;
    int getTotalRounds() const override { 
        return 9999; 
    }
    bool isGameOver() const override;
    void determineWinner() override;
    void flipTop();
    void reshuffleDeck();

private:
    std::unique_ptr<Card> topCard_;
    std::vector<std::unique_ptr<Card>> discardCards_;
};

#endif // UNO_GAME_H
