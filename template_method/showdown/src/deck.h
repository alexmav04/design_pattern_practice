#ifndef DECK_H
#define DECK_H

#include <vector>
#include "card.h"

class Deck {
public:
    Deck();
    
    void shuffle();
    Card drawCard();

protected:
    std::vector<Card> cards_;
};

#endif //DECK_H