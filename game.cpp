#include "game.h"

void play_game(AnimationWindow window) {
    while (!window.should_close()) {  //Makes it so the game stops when the window closes
        //The game

        window.next_frame();
    }
}