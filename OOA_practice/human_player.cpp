#include "human_player.h"
#include <limits>

HumanPlayer::HumanPlayer() 
{

}

void HumanPlayer::nameHimself() {
    std::cout << "Enter your name: ";
    std::cin >> name_;
}

bool HumanPlayer::wantExchange() {
    if (hasExchanged_) {
        return false;
    }

    char choice;
    while (true) {
        std::cout << name_ << " want to exchange hands with the other player? (y/n): ";
        std::cin >> choice;

        if (choice == 'y' || choice == 'Y') {
            return true;
        } else if (choice == 'n' || choice == 'N') {
            return false;
        } else {
            std::cout << "Please enter 'y' for yes or 'n' for no.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}

int HumanPlayer::chooseExchangePlayer() {
    int playerIndex;
    while (true) {
        std::cout << "Enter the index of the player you want to exchange hands with: ";
        std::cin >> playerIndex;

        if (std::cin.fail()) {
            std::cout << "Invalid input. Please enter a number between 0 and 3.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        if (playerIndex >= 0 && playerIndex < 4) {
            return playerIndex;
        } else {
            std::cout << "Invalid player index. Please enter a number between 0 and 3.\n";
        }
    }
}

Card HumanPlayer::show() {
    std::cout << name_ << "'s hand: ";

    int i = 0;
    for (const Card& card : hands_) {
        std::cout << "(" << i << ")" << card.toString() << " / ";
        i++;
    }
    std::cout << std::endl;

    size_t index;
    while (true) {
        std::cout << "Enter the index of the card you want to play: ";
        std::cin >> index;

        if (std::cin.fail()) {
            std::cout << "Invalid input. Please enter a number.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        if (index >= 0 && index < hands_.size()) {
            break;
        } else {
            std::cout << "Invalid index. Please enter a number between 0 and " << hands_.size() - 1 << ".\n";
        }
    }

    Card card = hands_[index];
    hands_.erase(hands_.begin() + index);

    return card;
}
