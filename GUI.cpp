#include "GUI.h"

// buttons

Button make_play_button(int posx, int posy, int width, int height) {
    const TDT4102::Point buttonPosition {posx, posy};
    const unsigned int buttonWidth = width;
    const unsigned int buttonHeight = height;
    const string buttonLabel = "Play";
    TDT4102::Button play_button {buttonPosition, buttonWidth, buttonHeight, buttonLabel};
    play_button.setButtonColor(TDT4102::Color::red);
    play_button.setButtonColorHover(TDT4102::Color::orange_red);
    play_button.setButtonColorActive(TDT4102::Color::dark_red);
    play_button.setLabelColor(TDT4102::Color::white);
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

//Menu background for the play button and high score before staring the game
void menu_background(int height, int width, AnimationWindow& window){
    window.draw_rectangle(TDT4102::Point{0,0}, height, width, Color::deep_skyblue);
}
void text_background(AnimationWindow& window){
    TDT4102::Point location {250, 0}; //Start point of the text
    std::string message = "ANT"; // what the text is
    Color textColor = TDT4102::Color::dark_red;
    int fontSize = 120; 
    TDT4102::Font fontFace = TDT4102::Font::times_bold;
    window.draw_text(location, message, textColor, fontSize, fontFace); // Draws the message
}

// Callbacks

//Defintion for the diffrent states the gae can be inn


void play() {
    // Whatever happens when play is called
    std::cout << "Play" << std::endl;
    game_screen = "game";

}