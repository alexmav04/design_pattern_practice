#include "game.h"
#include <algorithm>

Game::Game() 
{
    
}

void Game::start() {
    deck_.shuffle();

    for (int i = 0; i < 4; ++i) {
        players_.push_back(new Player());
        players_[i]->nameHimself();
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

    std::cout << "Winner: " << maxCard.first->name() << " won this round.\n";
    maxCard.first->addPoint();
}

void Game::playGame() {
    for (int round = 0; round < 13; ++round) {
        std::cout << "Round " << round + 1 << std::endl;
        takeATurn();
    }
    determineWinner();
}

void Game::determineWinner() {
    auto winner = *std::max_element(players_.begin(), players_.end(), [](const auto& a, const auto& b) {
        return a->points() < b->points();
    });

    std::cout << winner->name() << " won the game and got " << winner->points() << " points.\n";
}
