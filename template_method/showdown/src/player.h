#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include "deck.h"

class Player {
public:
    Player();
    virtual ~Player() = default;

    void nameHimself();
    void drawCard(Deck& deck);
    virtual Card show() = 0;
    
    void addPoint();
    int points() const;
    std::string name() const;

protected:
    std::string name_;
    std::vector<Card> hands_;
    int points_;
};

#endif //PLAYER_H