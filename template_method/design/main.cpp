#include "game.h"
#include "uno/uno_game.h"
#include "showdown/showdown_game.h"
#include <iostream>
#include <memory>

int main(int argc, char* argv[]) {
    std::string gameType;

    if (argc > 1) {
        gameType = argv[1];
    } else {
        std::cout << "Choose game mode (uno/showdown): ";
        std::cin >> gameType;
    }
    std::unique_ptr<Game> game;

    if (gameType == "uno") {
        game = std::make_unique<UnoGame>();
    } else if (gameType == "showdown") {
        game = std::make_unique<ShowdownGame>();
    } else {
        std::cerr << "Invalid game mode. Use 'uno' or 'showdown'.\n";
        return 1;
    }

    game->start();
    game->playGame();
    
    return 0;
}
