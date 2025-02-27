#include "deck.h"
#include <random>
#include <stdexcept>
#include <algorithm>

Deck::Deck() {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 10; ++j) {
            cards_.push_back(Card(static_cast<Color>(i), j));
        }
    }
}

void Deck::shuffle() {
    std::random_device rd;
    std::mt19937 rng(rd());
    std::shuffle(cards_.begin(), cards_.end(), rng);
}

Card Deck::drawCard() {
    if (cards_.empty()) {
        throw std::runtime_error("Deck is empty! No more cards to draw.");
    }

    Card card = cards_.back();
    cards_.pop_back();
    return card;
}

bool Deck::isEmpty() const {
    return cards_.empty();
}
