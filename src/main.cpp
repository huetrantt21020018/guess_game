#include <iostream>
#include "../include/Game.h"

int main() {
    Game* game;
    while(true) {
        // Memory leak but cppcheck cannot detect
        game = new Game();
        game->Run();
    }

    return 0;
}