#ifndef SHOWDOWN_CARD_H
#define SHOWDOWN_CARD_H

#include "../card.h"
#include <string>
#include <iostream>

enum class Suit {
    Club,
    Diamond,
    Heart,
    Spade
};

enum class Rank {
    Two = 2,
    Three,
    Four,
    Five,
    Six,
    Seven,
    Eight,
    Nine,
    Ten,
    Jack,
    Queen,
    King,
    Ace
};

class ShowdownCard : public Card 
{
public:
    ShowdownCard(Rank rank, Suit suit);

    std::string toString() const override;
    bool operator>(const Card& card) const override;
    bool operator<(const Card& card) const override;
    bool operator==(const Card& card) const;

private:
    Rank rank_;
    Suit suit_;
};

#endif // SHOWDOWN_CARD_H