#include "game.h"
#include "human_player.h"
#include "ai_player.h"
#include <iostream>
#include <algorithm>

Game::Game() { }

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

    for (int i = 0; i < 13; ++i) {
        for (auto& player : players_) {
            player->drawCard(deck_);
        }
    }
}

void Game::takeATurn() {
    std::vector<std::pair<Player*, Card>> cardsOnTable;

    for (auto& player : players_) {
        Card card = player->show();
        cardsOnTable.push_back(std::make_pair(player, card));
    }
    revealAll(cardsOnTable);
}

void Game::revealAll(std::vector<std::pair<Player*, Card>> cards) {
    for (auto& card : cards) {
        std::cout << card.first->name() << " played " << card.second.toString() << std::endl;
    }

    auto maxCard = *std::max_element(cards.begin(), cards.end(), [](const auto& a, const auto& b) {
        return a.second < b.second;
    });

    std::cout << "\nWinner: " << maxCard.first->name() << " won this round.\n\n";
    maxCard.first->addPoint();
}

void Game::playGame() {
    for (int round = 0; round < 13; ++round) {
        std::cout << "\n------ Round " << round + 1 << "------" << std::endl;
        takeATurn();
    }
    determineWinner();
}

void Game::determineWinner() {
    auto winner = *std::max_element(players_.begin(), players_.end(), [](const auto& a, const auto& b) {
        return a->points() < b->points();
    });

    std::cout << " ==== Game Over ==== \n";
    std::cout << winner->name() << " won the game and got " << winner->points() << " points.\n";
}
