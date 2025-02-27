#include "game.h"
#include "human_player.h"
#include "ai_player.h"
#include <iostream>
#include <algorithm>

Game::Game() : topCard_(Color::BLUE, -1) {
    
}
void Game::start() {
    deck_.shuffle();
    
    for (int i = 0; i < 4; ++i) {
        char choice;
        while (true) {
            std::cout << "Is player " << i + 1 << " a human? (y/n): ";
            std::cin >> choice;

            if (choice == 'y' || choice == 'Y') {
                players_.emplace_back(new HumanPlayer());
                break;
            } else if (choice == 'n' || choice == 'N') {
                players_.emplace_back(new AIPlayer());
                break;
            } else {
                std::cout << "Please enter 'y' for human or 'n' for AI.\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }
        players_.back()->nameHimself();
    }

    for (int i = 0; i < 5; ++i) {
        for (auto& player : players_) {
            player->drawCard(deck_);
        }
    }
    flipTop();
}

void Game::flipTop() {
    do {
        topCard_ = deck_.drawCard();
    } while (topCard_.number() == -1);
    discardCards_.push_back(topCard_);
    std::cout << "Top card: " << topCard_.toString() << std::endl;
}

void Game::playGame() {
    int currentPlayer = 0;
    while (true) {
        Card playedCard = players_[currentPlayer]->playCard(topCard_);

        if (playedCard.number() == -1) {
            if (deck_.isEmpty()) {
                reshuffleDeck();
            }
            players_[currentPlayer]->drawCard(deck_);
            std::cout << players_[currentPlayer]->name() << " drew a card.\n";
        } else {
            topCard_ = playedCard;
            discardCards_.push_back(playedCard);
            std::cout << players_[currentPlayer]->name() << " played " << playedCard.toString() << ".\n";
        }

        if (players_[currentPlayer]->emptyHand()) {
            std::cout << "\n===== " << players_[currentPlayer]->name() << " wins! =====\n\n";
            break;
        }

        currentPlayer = (currentPlayer + 1) % 4;
    }
}

void Game::reshuffleDeck() {
    if (discardCards_.size() > 1) {
        std::cout << "Reshuffling...\n";

        std::vector<Card> newDeck(discardCards_.begin(), discardCards_.end() - 1);
        discardCards_.clear();
        discardCards_.push_back(topCard_);

        deck_ = Deck();
        deck_.shuffle();
    }
}