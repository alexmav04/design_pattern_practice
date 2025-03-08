#ifndef CARD_H
#define CARD_H

#include <string>

enum class Rank
{
    Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King, Ace
};

enum class Suit
{
    Club, Diamond, Heart, Spade
};

class Card 
{
public:
    Card(Rank rank, Suit suit);

    Rank rank() const;

    Suit suit() const;

    std::string toString() const;

    bool operator>(const Card& card) const;

    bool operator<(const Card& card) const;

    bool operator==(const Card& card) const;

private:
    Rank rank_;
    Suit suit_;
};

#endif // CARD_H