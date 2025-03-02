#include "showdown_deck.h"
#include "showdown_card.h"

ShowdownDeck::ShowdownDeck() {
    for (int i = 0; i < 4; ++i) {
        for (int j = 2; j < 15; ++j) {
            cards_.emplace_back(std::make_unique<ShowdownCard>(static_cast<Rank>(j), static_cast<Suit>(i)));
        }
    }
}