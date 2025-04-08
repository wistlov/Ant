#include "std_lib_facilities.h"
#include "AnimationWindow.h"
#include "grid.h"
#include "GUI.h"
#include "game.h"
#include "ant.h"


//------------------------------------------------------------------------------'

// C++ programs start by executing the function main
int main() {

    AnimationWindow win{400, 25, 832, 832, "Ant"}; // Makes the game window
    play_game(win); // Starts the game function 

    return 0;
}


//------------------------------------------------------------------------------
