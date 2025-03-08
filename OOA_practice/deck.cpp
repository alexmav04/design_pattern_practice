#include "deck.h"
#include <random>
#include <algorithm>

Deck::Deck()
{
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 13; j++) {
            cards_.push_back(Card(static_cast<Rank>(j), static_cast<Suit>(i)));
        }
    }
}

void Deck::shuffle() {
    std::random_device rd;
    std::mt19937 rng(rd());
    std::shuffle(cards_.begin(), cards_.end(), rng);
}

Card Deck::drawCard() {
    Card card = cards_.back();
    cards_.pop_back();
    return card;
}