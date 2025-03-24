#include "GUI.h"
#include "game.h"


// Linking the global variable
// extern std::string game_screen;


// buttons

Button make_play_button(int posx, int posy, int width, int height, AnimationWindow& window) {
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


//Menu background for the play button and high score before staring the game

TDT4102::Image Image1("Images/cute_ant.gif"); // Defin the image of the ant
TDT4102::Image Image2("Images/cute_ant_move2.gif");

int ant_walkning = 768;
int frame_step = 0;

// Makes the ANT text
TDT4102::Point location {295, 0}; //Start point of the text
std::string message = "ANT"; // what the text is
Color textColor = TDT4102::Color::dark_red;
int fontSize = 120; 
TDT4102::Font fontFace = TDT4102::Font::times_bold;

// This here is the menu function that runs when the menu is up
void menu_overall_background(int width, int height, AnimationWindow& window){

    window.draw_rectangle(TDT4102::Point{0,0}, width, height,  Color::deep_skyblue);
    window.draw_rectangle(TDT4102::Point{0,600}, width, height, Color::sandy_brown);
    window.draw_rectangle(TDT4102::Point{0,700}, width, 80, Color::saddle_brown);
    window.draw_rectangle(TDT4102::Point{0,600}, width, 20, Color::lawn_green);
    
    window.draw_text(location, message, textColor, fontSize, fontFace); // Draws the message

    frame_step = frame_step + 1; //To change image
    ant_walkning = ant_walkning - 8; // Amounts of pixel the ants move each frame
    TDT4102::Point ant_start_walk1 {ant_walkning,(600-48)}; //Start point for the ant
    TDT4102::Point ant_start_walk2 {ant_walkning+64,(600-48)};
    TDT4102::Point ant_start_walk3 {ant_walkning+128,(600-48)};

    if(frame_step % 2 == 0){
        window.draw_image(ant_start_walk1, Image1, 64, 64); //Draws the first and image
        window.draw_image(ant_start_walk2, Image1, 64, 64);
        window.draw_image(ant_start_walk3, Image1, 64, 64);
    }
    else {
        window.draw_image(ant_start_walk1, Image2, 64, 64); //Draws the second ant image
        window.draw_image(ant_start_walk2, Image2, 64, 64);
        window.draw_image(ant_start_walk3, Image2, 64, 64);
    }

    window.wait_for(0.2);
    
}

// Callbacks

//Defintion for the diffrent states the gae can be inn


void play() {
    // Whatever happens when play is called
    std::cout << "Play" << std::endl;
    game_screen = "game";
    std::cout << game_screen << std::endl;

}