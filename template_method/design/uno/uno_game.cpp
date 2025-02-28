#include "uno_game.h"
#include "uno_human_player.h"
#include "uno_ai_player.h"
#include "uno_deck.h"
#include <iostream>

UnoGame::UnoGame() {
    deck_ = std::make_unique<UnoDeck>();
}

void UnoGame::setupPlayers() {
    for (int i = 0; i < 4; ++i) {
        char choice;
        while (true) {
            std::cout << "Is player " << i + 1 << " a human? (y/n): ";
            std::cin >> choice;

            if (choice == 'y' || choice == 'Y') {
                players_.emplace_back(std::make_unique<UnoHumanPlayer>());
                break;
            } else if (choice == 'n' || choice == 'N') {
                players_.emplace_back(std::make_unique<UnoAIPlayer>());
                break;
            } else {
                std::cout << "Please enter 'y' for human or 'n' for AI.\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }
        players_.back()->nameHimself();
    }
}

void UnoGame::dealInitialCards() {
    for (int i = 0; i < 5; ++i) {
        for (auto& player : players_) {
            player->drawCard(deck_->drawCard());
        }
    }
    flipTop();
}

void UnoGame::flipTop() {
    do {
        topCard_ = deck_->drawCard();
    } while (dynamic_cast<UnoCard*>(topCard_.get())->number() == -1);

    std::cout << "\nTop card: " << topCard_->toString() << std::endl;
    // discardCards_.push_back(std::move(topCard_));
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
            std::cout << "\n===== " << player->name() << " wins! =====\n";
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
    std::cout << " ==== Game Over ==== \n";
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

