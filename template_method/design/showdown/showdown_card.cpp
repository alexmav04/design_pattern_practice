#include "showdown_card.h"

ShowdownCard::ShowdownCard(Rank rank, Suit suit)
    : rank_(rank), suit_(suit)
{

}

std::string ShowdownCard::toString() const {
    std::string ranks[] = {
        "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"
    };
    std::string suits[] = {
        "Club", "Diamond", "Heart", "Spade"
    };
    return ranks[static_cast<int>(rank_) - 2] + " / " + suits[static_cast<int>(suit_)];
}

bool ShowdownCard::operator>(const Card& card) const {
    const ShowdownCard& showdownCard = dynamic_cast<const ShowdownCard&>(card);
    if (rank_ != showdownCard.rank_) {
        return static_cast<int>(rank_) > static_cast<int>(showdownCard.rank_);
    }
    return static_cast<int>(suit_) > static_cast<int>(showdownCard.suit_);
}

bool ShowdownCard::operator<(const Card& card) const {
    const ShowdownCard& showdownCard = dynamic_cast<const ShowdownCard&>(card);
    return showdownCard > *this;
}

bool ShowdownCard::operator==(const Card& card) const {
    const ShowdownCard& showdownCard = dynamic_cast<const ShowdownCard&>(card);
    return rank_ == showdownCard.rank_ && suit_ == showdownCard.suit_;
}