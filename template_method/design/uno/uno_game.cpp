#include "uno_game.h"
#include "uno_human_player.h"
#include "uno_ai_player.h"
#include "uno_deck.h"
#include <iostream>

UnoGame::UnoGame() {
    deck_ = std::make_unique<UnoDeck>();
}

std::unique_ptr<Player> UnoGame::createHumanPlayer() {
    return std::make_unique<UnoHumanPlayer>();
}

std::unique_ptr<Player> UnoGame::createAIPlayer() {
    return std::make_unique<UnoAIPlayer>();
}

int UnoGame::initialCardCount() const {
    return 5;
}

void UnoGame::otherCardSetup() {
    flipTop();
}

void UnoGame::flipTop() {
    do {
        topCard_ = deck_->drawCard();
    } while (dynamic_cast<UnoCard*>(topCard_.get())->number() == -1);

    std::cout << "\nTop card: " << topCard_->toString() << std::endl;
}

void UnoGame::takeATurn() {
    for (auto& player : players_) {
        std::cout << "\n" << player->name() << "'s turn" << std::endl;
        std::cout << "Top card: " << topCard_->toString() << "\n";

        auto playedCard = player->playCard(*topCard_);
        if (playedCard) {
            discardCards_.push_back(std::move(topCard_));
            topCard_ = std::move(playedCard);
            std::cout << player->name() << " played " << topCard_->toString() << ".\n";
        } else {
            std::cout << player->name() << " drew a card.\n";
            if (deck_->isEmpty()) {
                reshuffleDeck();
            }
            player->drawCard(deck_->drawCard());
        }

        if (player->emptyHand()) {
            return;
        }
    }
}

bool UnoGame::isGameOver() const {
    for (const auto& player : players_) {
        if (player->emptyHand()) {
            return true;
        }
    }
    return false;
}

void UnoGame::determineWinner() {
    std::cout << "\n ==== Game Over ==== \n";
    for (const auto& player : players_) {
        if (player->emptyHand()) {
            std::cout << player->name() << " wins the game!\n";
            return;
        }
    }
}

void UnoGame::reshuffleDeck() {
    if (discardCards_.size() > 0) {
        std::cout << "Reshuffling...\n";

        std::vector<std::unique_ptr<Card>> newDeck;
        newDeck.reserve(discardCards_.size());
        for (auto &card : discardCards_) {
            newDeck.push_back(std::move(card));
        }
        discardCards_.clear();

        deck_->addCards(std::move(newDeck));
        deck_->shuffle();
    }
}

