#include "showdown_human_player.h"
#include "showdown_card.h"

ShowdownHumanPlayer::ShowdownHumanPlayer() 
{

}

std::unique_ptr<Card> ShowdownHumanPlayer::show() {
    std::cout << "\n" << name_ << " hands:\n";
    for (size_t i = 0; i < hands_.size(); ++i) {
        std::cout << "(" << i << ") " << hands_[i]->toString() << "\n";
    }

    int choice;
    while (true) {
        std::cout << "Choose a card index to play: ";
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Try again.\n";
            continue;
        }

        if (choice >= 0 && choice < static_cast<int>(hands_.size())) {
            break;
        }
        std::cout << "Invalid choice. Try again.\n";
    }

    std::unique_ptr<Card> playedCard = std::move(hands_[choice]);
    hands_.erase(hands_.begin() + choice);
    return playedCard;
}