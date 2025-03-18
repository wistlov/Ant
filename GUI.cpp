#include "GUI.h"

// buttons

Button make_play_button(int posx, int posy, int width, int height) {
    const TDT4102::Point buttonPosition {posx, posy};
    const unsigned int buttonWidth = width;
    const unsigned int buttonHeight = height;
    const string buttonLabel = "Play";
    TDT4102::Button play_button {buttonPosition, buttonWidth, buttonHeight, buttonLabel};
    play_button.setCallback(play); //This is what happens when the button is clicked.
    return play_button;
}
/*
The make_play_button will create a play button by assigning it to a variable. Should do:
Button play_button = make_play_button(x,y,w,h);
in main() before the game begins.
*/

void show_button(Button button, AnimationWindow window) {
    window.add(button);
}
/*
If you want the button in question to show up, call this function for that button. 
It will only show and be accessable while this function is being called. In theory.

Unfortunately, this doesnt work as unless wait_until_window_close() is called inside the function, this closes the window. 
Therefore: window.add(button) must be done manually instead of using the function
*/

// Callbacks

void play() {
    // Whatever happens when play is called
    std::cout << "Play" << std::endl;
}