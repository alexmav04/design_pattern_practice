#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include <memory>
#include <iostream>
#include "deck.h"

class Player 
{
public:
    Player();

    virtual void nameHimself() = 0;

    void drawCard(Deck& deck);

    virtual bool wantExchange() = 0;

    virtual int chooseExchangePlayer() = 0;

    virtual Card show() = 0;

    void addPoint();

    int points() const;

    std::string name() const;

    std::vector<Card>& hands();

    bool hasExchanged() const;

    void changeExchangedStatus();

protected:
    std::string name_;
    std::vector<Card> hands_;
    bool hasExchanged_ = false;
    int points_;
};

#endif //PLAYER_H