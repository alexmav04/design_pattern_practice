#ifndef DECK_H
#define DECK_H

#include "card.h"
#include <vector>
#include <memory>
#include <random>
#include <algorithm>
#include <chrono>

class Deck {
protected:
    std::vector<std::unique_ptr<Card>> cards_;

public:
    virtual ~Deck() = default;

    virtual void shuffle();

    virtual std::unique_ptr<Card> drawCard();

    void addCards(std::vector<std::unique_ptr<Card>>&& extraCards);

    virtual bool isEmpty() const;
};

#endif //DECK_H