#include "showdown_game.h"
#include "showdown_human_player.h"
#include "showdown_ai_player.h"
#include "showdown_deck.h"
#include <memory>

ShowdownGame::ShowdownGame() : currentRound_(0) {
    deck_ = std::make_unique<ShowdownDeck>();
}

void ShowdownGame::setupPlayers() {   
    for (int i = 0; i < 4; ++i) {
        char choice;
        while (true) {
            std::cout << "Is player " << i + 1 << " a human? (y/n): ";
            std::cin >> choice;

            if (choice == 'y' || choice == 'Y') {
                players_.push_back(std::make_unique<ShowdownHumanPlayer>());
                break;
            } else if (choice == 'n' || choice == 'N') {
                players_.push_back(std::make_unique<ShowdownAIPlayer>());
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

void ShowdownGame::dealInitialCards() {
    for (int i = 0; i < 13; ++i) {
        for (auto& player : players_) {
            player->drawCard(deck_->drawCard());
        }
    }
}

void ShowdownGame::takeATurn() {
    std::vector<std::pair<Player*, std::unique_ptr<Card>>> cardsOnTable;

    for (auto& player : players_) {
        std::unique_ptr<Card> card = player->show();
        cardsOnTable.emplace_back(player.get(), std::move(card));
    }
    revealAll(cardsOnTable);
    currentRound_++;
}

int ShowdownGame::getTotalRounds() const {
    return 13;
}

bool ShowdownGame::isGameOver() const {
    return currentRound_ >= getTotalRounds();
}

void ShowdownGame::determineWinner() {
    auto winner = std::max_element(players_.begin(), players_.end(),
        [](const std::unique_ptr<Player>& a, const std::unique_ptr<Player>& b) {
            return a->points() < b->points();
        });

    std::cout << " ==== Game Over ==== \n";
    std::cout << winner->get()->name() << " won the game and got " << winner->get()->points() << " points.\n";
}

void ShowdownGame::revealAll(const std::vector<std::pair<Player*, std::unique_ptr<Card>>>& cards) {
    for (auto& card : cards) {
        std::cout << card.first->name() << " played " << card.second->toString() << std::endl;
    }

    auto winnerIt = std::max_element(cards.begin(), cards.end(),
    [](const std::pair<Player*, std::unique_ptr<Card>>& a,
       const std::pair<Player*, std::unique_ptr<Card>>& b) {
        return (*(a.second) > *(b.second)) || ((!(*(b.second) > *(a.second))) && a.first->name() < b.first->name());
    });

    std::cout << "\nWinner: " << winnerIt->first->name() << " won this round.\n\n";
    winnerIt->first->addPoint();
}

