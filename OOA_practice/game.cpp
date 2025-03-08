#include "game.h"
#include "human_player.h"
#include "ai_player.h"
#include <algorithm>

Game::Game() 
{

}

void Game::start() {
    std::cout << "Welcome to the game!" << std::endl;
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

    deck_ = std::make_unique<Deck>();
    deck_->shuffle();

    for (int i = 0; i < 13; ++i) {
        for (auto& player : players_) {
            player->drawCard(*deck_);
        }
    }

    while (round_ <= 13) {
        if (round_ > 1) {
            revertHands();
        }
        takeTurn();
        round_++;
    }

    determineWinner();
}

void Game::takeTurn() {
    std::vector<std::pair<int, Card>> cardsOnTable;
    std::cout << "\n======== Round " << round_ << " ========"<< std::endl;
    for (size_t i = 0; i < players_.size(); ++i) {
        auto& player = players_[i];
        std::cout << player->name() << "'s turn." << std::endl;

        // check if the player wants to exchange hands with another player
        if (round_ != 1) {
            if (player->wantExchange() && !player->hasExchanged()) {
                size_t exchangePlayerIndex;
                while (true) {
                    exchangePlayerIndex = player->chooseExchangePlayer();
    
                    if (exchangePlayerIndex != i && exchangePlayerIndex < players_.size()) {
                        break;
                    }
                    std::cout << "Invalid choice, please choose another player." << std::endl;
                }
    
                if (exchangePlayerIndex == i || exchangePlayerIndex >= players_.size()) {
                    std::cout << player->name() << " could not find a valid player to exchange hands." << std::endl;
                }
                
                std::cout << player->name() << " exchanges hands with " << players_[exchangePlayerIndex]->name() << std::endl;
                std::swap(player->hands(), players_[exchangePlayerIndex]->hands());
                player->changeExchangedStatus();
    
                exchangeHistory_[round_ + 3].emplace_back(i, exchangePlayerIndex);
            }
        }

        // player shows a card
        if (player->hands().empty()) {
            std::cout << player->name() << " has no more cards." << std::endl;
            std::cout << std::endl;
            continue;
        }
        Card card = player->show();
        std::cout << std::endl;

        cardsOnTable.emplace_back(i, card);
    }

    // determine the winner of this round
    if (cardsOnTable.empty()) {
        std::cout << "No cards were played this round." << std::endl;
        return;
    }

    std::cout << "\nResult: " << std::endl;
    for (size_t i = 0; i < cardsOnTable.size(); ++i) {
        std::cout << players_[cardsOnTable[i].first]->name() << " plays " << cardsOnTable[i].second.toString() << std::endl;
    }
    auto maxCard = std::max_element(cardsOnTable.begin(), cardsOnTable.end(), 
    [](const std::pair<int, Card>& a, const std::pair<int, Card>& b) {
        return a.second < b.second;
    });
    players_[maxCard->first]->addPoint();
    std::string winner = players_[maxCard->first]->name();

    std::cout << "Winner: " << winner << std::endl;
    std::cout << "==============================" << std::endl;
    std::cout << std::endl;
}

void Game::revertHands() {
    for (const auto& exchange : exchangeHistory_[round_]) {
        std::swap(players_[exchange.first]->hands(), players_[exchange.second]->hands());
    }
}

void Game::determineWinner() {
    auto maxPlayer = std::max_element(players_.begin(), players_.end(), 
        [](const std::unique_ptr<Player>& a, const std::unique_ptr<Player>& b) {
            return a->points() < b->points();
        });

    std::cout << "******* Game over! *******" << std::endl;
    std::cout << "The winner is " << (*maxPlayer)->name() << " with " << (*maxPlayer)->points() << " points!" << std::endl;
}