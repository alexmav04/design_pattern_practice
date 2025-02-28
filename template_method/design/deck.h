#ifndef DECK_H
#define DECK_H

#include "card.h"
#include <vector>
#include <memory>
#include <random>
#include <algorithm>

class Deck {
protected:
    std::vector<std::unique_ptr<Card>> cards_;

public:
    virtual ~Deck() = default;

    virtual void shuffle() {
        std::random_device rd;
        std::mt19937 rng(rd());
        std::shuffle(cards_.begin(), cards_.end(), rng);
    }

    virtual std::unique_ptr<Card> drawCard() {
        if (cards_.empty()) {
            throw std::runtime_error("Deck is empty! No more cards to draw.");
        }
        std::unique_ptr<Card> card = std::move(cards_.back());
        cards_.pop_back();
        return card;
    }

    void addCards(std::vector<std::unique_ptr<Card>>&& extraCards) {
        for (auto& c : extraCards) {
            cards_.push_back(std::move(c));
        }
    }

    virtual bool isEmpty() const { 
        return cards_.empty(); 
    }
};

#endif //DECK_H