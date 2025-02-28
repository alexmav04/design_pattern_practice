#ifndef PLAYER_H
#define PLAYER_H

#include "card.h"
#include "deck.h"
#include <vector>
#include <memory>
#include <string>

class Player {
public:
    virtual ~Player() = default;

    virtual void nameHimself() {
        std::cout << "Enter player name: ";
        std::cin >> name_;
    }

    virtual void drawCard(std::unique_ptr<Card> card) {
        hands_.push_back(std::move(card));
    }

    virtual std::unique_ptr<Card> show() = 0;
    
    virtual std::unique_ptr<Card> playCard(const Card& topCard) = 0;

    virtual bool hasPlayableCard(const Card& topCard) const { 
        return false; 
    }
    
    virtual bool emptyHand() const { 
        return hands_.empty(); 
    }

    void addPoint() { 
        points_++; 
    }

    int points() const { 
        return points_; 
    }

    std::string name() const {
         return name_; 
    }

protected:
    std::string name_;
    std::vector<std::unique_ptr<Card>> hands_;
    int points_ = 0;
};

#endif //PLAYER_H