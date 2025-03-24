//
// This is example code from Chapter 2.2 "The classic first program" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//
// This program outputs the message "Hello, World!" to the monitor

#include "std_lib_facilities.h"
#include "AnimationWindow.h"
#include "grid.h"
#include "GUI.h"
#include "game.h"

//------------------------------------------------------------------------------'

// C++ programs start by executing the function main
int main() {
    TDT4102::Image Image1("cute_ant.gif");
    TDT4102::Image Image2("cute_ant_move2.gif");

    AnimationWindow win{400, 25, 750, 750, "Ant"}; // Makes the game window
    play_game(win); // Starts the game function 


    // This lets the operating system (Windows, Mac, Linux, etc.) know that the program
    // did not encounter any errors
    return 0;
}


//------------------------------------------------------------------------------
