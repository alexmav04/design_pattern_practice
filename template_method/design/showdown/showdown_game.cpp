#include "showdown_game.h"
#include "showdown_human_player.h"
#include "showdown_ai_player.h"
#include "showdown_deck.h"
#include <memory>

ShowdownGame::ShowdownGame() : currentRound_(0) {
    deck_ = std::make_unique<ShowdownDeck>();
}

std::unique_ptr<Player> ShowdownGame::createHumanPlayer() {
    return std::make_unique<ShowdownHumanPlayer>();
}

std::unique_ptr<Player> ShowdownGame::createAIPlayer() {
    return std::make_unique<ShowdownAIPlayer>();
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

int ShowdownGame::initialCardCount() const {
    return 13;
}

bool ShowdownGame::isGameOver() const {
    return currentRound_ >= initialCardCount();
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

