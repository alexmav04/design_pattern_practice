#ifndef PLAYER_H
#define PLAYER_H

#include "card.h"
#include "deck.h"
#include <vector>
#include <memory>
#include <string>

class Player {
public:
    virtual ~Player() = default;

    void nameHimself();

    std::string name() const;

    void drawCard(std::unique_ptr<Card> card);

    virtual std::unique_ptr<Card> show() = 0;
    
    virtual std::unique_ptr<Card> playCard(const Card& topCard) = 0;

    bool hasPlayableCard(const Card& topCard) const;
    
    bool emptyHand() const;

    void addPoint();

    int points() const;

protected:
    std::string name_;
    std::vector<std::unique_ptr<Card>> hands_;
    int points_ = 0;
};

#endif //PLAYER_H