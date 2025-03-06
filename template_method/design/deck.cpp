#include "deck.h"

void Deck::shuffle() {
    static std::mt19937 rng(std::chrono::system_clock::now().time_since_epoch().count());
    std::shuffle(cards_.begin(), cards_.end(), rng);
}

std::unique_ptr<Card> Deck::drawCard() {
    if (cards_.empty()) {
        throw std::runtime_error("Deck is empty! No more cards to draw.");
    }
    std::unique_ptr<Card> card = std::move(cards_.back());
    cards_.pop_back();
    return card;
}

void Deck::addCards(std::vector<std::unique_ptr<Card>>&& extraCards) {
    for (auto& c : extraCards) {
        cards_.push_back(std::move(c));
    }
}

bool Deck::isEmpty() const { 
    return cards_.empty(); 
}