#include "ai_player.h"
#include <ctime>

AIPlayer::AIPlayer() 
{

}

void AIPlayer::nameHimself() {
    name_ = generateRandomName();
    std::cout << "AI player: " << name_ << " has joined the game." << std::endl;
}

bool AIPlayer::wantExchange() {
    if (hasExchanged_) {
        return false;
    }

    bool wantExchange = rand() % 2;
    if (!wantExchange) {
        std::cout << name_ << " doesn't want to exchange hands with the other player." << std::endl;
    }
    return wantExchange;
}

int AIPlayer::chooseExchangePlayer() {
    return rand() % 4;
}

Card AIPlayer::show() {
    std::cout << name_ << "'s hand: " << std::endl;
    int i = 0;
    for (const Card& card : hands_) {
        std::cout << "(" << i << ")" << card.toString() << " / ";
        i++;
    }
    std::cout << std::endl;

    int index = rand() % hands_.size();

    Card card = hands_[index];
    hands_.erase(hands_.begin() + index);

    return card;
}

std::string AIPlayer::generateRandomName() {
    std::string name = "AI_";
    for (int i = 0; i < 3; ++i) {
        char randomChar = 'A' + (std::rand() % 26);
        name += randomChar;
    }
    return name;
}