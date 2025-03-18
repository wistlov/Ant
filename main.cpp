//
// This is example code from Chapter 2.2 "The classic first program" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//
// This program outputs the message "Hello, World!" to the monitor

#include "std_lib_facilities.h"
#include "AnimationWindow.h" 
#include "grid.h"
#include "GUI.h"


//------------------------------------------------------------------------------'

// C++ programs start by executing the function main
int main() {
    // Show a nice message in the Terminal window
    cout << "Hello, Ant! Im here for your food." << endl;
    AnimationWindow win{400, 25, 750, 750, "Ant"};
    Grid(15, 15, 750, 750, win);



    //Button stuff
    Button play_button = make_play_button(300, 300, 100, 50); //Testing play button
    //show_button(play_button, win);   //This didnt work but the code below does the same thing
    win.add(play_button); //This is what makes the button show up





    win.wait_for_close();

    // This lets the operating system (Windows, Mac, Linux, etc.) know that the program
    // did not encounter any errors
    return 0;
}

//------------------------------------------------------------------------------
