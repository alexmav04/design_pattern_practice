#ifndef CARD_H
#define CARD_H

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

class Card {
public:
    Card(Rank rank, Suit suit);

    std::string toString() const;
    bool operator>(const Card& card) const;
    bool operator<(const Card& card) const;
    bool operator==(const Card& card) const;

private:
    Rank rank_;
    Suit suit_;
};

#endif //CARD_H
