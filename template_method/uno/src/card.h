#ifndef CARD_H
#define CARD_H

#include <string>
#include <iostream>

enum class Color {
    BLUE,
    RED,
    YELLOW,
    GREEN
};

class Card {
public:
    Card(Color color, int number);

    int number() const;
    std::string toString() const;
    bool canBePlayed(const Card& card) const;

private:
    Color color_;
    int number_;
};

#endif //CARD_H
