#ifndef UNO_PLAYER_H
#define UNO_PLAYER_H

#include "../player.h"

class UnoPlayer : public Player {
public:
    virtual ~UnoPlayer() = default;

    std::unique_ptr<Card> show() override {
        return nullptr;
    }
};

#endif // UNO_PLAYER_H