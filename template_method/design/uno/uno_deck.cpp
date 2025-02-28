#include "uno_deck.h"
#include <memory>

UnoDeck::UnoDeck() {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 10; ++j) {
            cards_.emplace_back(std::make_unique<UnoCard>(static_cast<Color>(i), j));
        }
    }
}
