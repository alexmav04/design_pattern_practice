#include "game.h"

void Game::start() {
    deck_->shuffle();
    setupPlayers();
    dealInitialCards();
}

void Game::playGame() {
    int i = 1;
    while (!isGameOver()) {
        std::cout << "\n==== Round " << i++ << " ====\n";
        takeATurn();
    }
    determineWinner();
}

void Game::setupPlayers() {
    for (int i = 0; i < 4; ++i) {
        char choice;
        while (true) {
            std::cout << "Is player " << i + 1 << " a human? (y/n): ";
            std::cin >> choice;

            if (choice == 'y' || choice == 'Y') {
                players_.emplace_back(createHumanPlayer());
                break;
            } else if (choice == 'n' || choice == 'N') {
                players_.emplace_back(createAIPlayer());
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

void Game::dealInitialCards() {
    int counts = initialCardCount();
    for (int i = 0; i < counts; ++i) {
        for (auto& player : players_) {
            player->drawCard(deck_->drawCard());
        }
    }
    otherCardSetup();
}
