#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include "deck.h"

class Player {
public:
    Player();

    void nameHimself();
    bool hasPlayableCard(const Card& card) const;
    void drawCard(Deck& deck);
    virtual Card playCard(const Card& topCard) = 0; 
    bool emptyHand() const;
    
    std::string name() const;

protected:
    std::string name_;
    std::vector<Card> hands_;
};

#endif //PLAYER_H