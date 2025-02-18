#include "card.h"

Card::Card(Rank rank, Suit suit) 
    : rank_(rank), suit_(suit) 
{

}

std::string Card::toString() const {
    std::string ranks[] = {
        "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"
    };
    std::string suits[] = {
        "Club", "Diamond", "Heart", "Spade"
    };
    return ranks[static_cast<int>(rank_) - 2] + " / " + suits[static_cast<int>(suit_)];
}

bool Card::operator>(const Card& card) const {
    if (rank_ != card.rank_) {
        return rank_ > card.rank_;
    }
    return suit_ > card.suit_;
}

bool Card::operator<(const Card& card) const {
    return card > *this;
}

bool Card::operator==(const Card& card) const {
    return rank_ == card.rank_ && suit_ == card.suit_;
}
