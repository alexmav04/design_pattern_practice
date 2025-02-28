#ifndef CARD_H
#define CARD_H

#include <iostream>

class Card {
public:
    virtual ~Card() = default;

    virtual std::string toString() const = 0;

    virtual bool operator>(const Card& card) const = 0;
    
    virtual bool operator<(const Card& card) const = 0;
   
    virtual bool canBePlayed(const Card& topCard) const { 
        return false; 
    }
};

#endif //CARD_H