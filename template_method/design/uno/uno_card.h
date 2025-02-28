#ifndef UNO_CARD_H
#define UNO_CARD_H

#include "../card.h"

enum class Color { 
    BLUE, 
    RED, 
    YELLOW, 
    GREEN
};

class UnoCard : public Card {
public:
    UnoCard(Color color, int number);

    std::string toString() const override;
    bool operator>(const Card& card) const override;
    bool operator<(const Card& card) const override;
    bool canBePlayed(const Card& topCard) const override;
    
    Color color() const;
    int number() const;

private:
    Color color_;
    int number_;
};

#endif // UNO_CARD_H
