#include "GUI.h"
#include "ant.h"

// Image for the mountain
TDT4102::Image Mountain("Images/mountain.png"); //Define the mountain image

// buttons

/*
The make_play_button will create a play button by assigning it to a variable. Should do:
Button play_button = make_play_button(x,y,w,h);
in main() before the game begins.
*/
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

Button make_highscore_button(int posx, int posy, int width, int height, AnimationWindow& window) {
    const TDT4102::Point buttonPosition {posx, posy};
    const unsigned int buttonWidth = width;
    const unsigned int buttonHeight = height;
    const string buttonLabel = "HighScore";
    TDT4102::Button highscore_button {buttonPosition, buttonWidth, buttonHeight, buttonLabel};
    highscore_button.setButtonColor(TDT4102::Color::red);
    highscore_button.setButtonColorHover(TDT4102::Color::orange_red);
    highscore_button.setButtonColorActive(TDT4102::Color::dark_red);
    highscore_button.setLabelColor(TDT4102::Color::white);
    highscore_button.setCallback(highscore); //This is what happens when the button is clicked.
    return highscore_button;
}

Button make_quit_button(int posx, int posy, int width, int height, AnimationWindow& window) {
    const TDT4102::Point buttonPosition {posx, posy};
    const unsigned int buttonWidth = width;
    const unsigned int buttonHeight = height;
    const string buttonLabel = "Quit";
    TDT4102::Button quit_button {buttonPosition, buttonWidth, buttonHeight, buttonLabel};
    quit_button.setButtonColor(TDT4102::Color::red);
    quit_button.setButtonColorHover(TDT4102::Color::orange_red);
    quit_button.setButtonColorActive(TDT4102::Color::dark_red);
    quit_button.setLabelColor(TDT4102::Color::white);
    quit_button.setCallback(quit); //This is what happens when the button is clicked.
    return quit_button;
}

// Makes the ANT text
TDT4102::Point location {295, 0}; //Start point of the text
std::string message = "ANT"; // what the text is
Color textColor = TDT4102::Color::dark_red;
int fontSize = 120; 
TDT4102::Font fontFace = TDT4102::Font::times_bold;


// This here is the menu function that runs when the menu is up
void menu_overall_background(int width, int height, AnimationWindow& window){

    //Background
    window.draw_rectangle(TDT4102::Point{0,636}, width, height, Color::sandy_brown);
    window.draw_rectangle(TDT4102::Point{0,700}, width, 60, Color::saddle_brown);
    window.draw_rectangle(TDT4102::Point{0,626}, width, 20, Color::lawn_green);
    
    window.draw_text(location, message, textColor, fontSize, fontFace); // Draws the message

    //Mountain background
    window.draw_image(TDT4102::Point{0,200}, Mountain, 832, 426);
    
}


//Escape to main menu
void Esacpe_menu(AnimationWindow& window) {
    bool Esc_key_is_pressed = window.is_key_down(KeyboardKey::ESCAPE);
    if(Esc_key_is_pressed) {
        game_screen = "menu";
    }}

void quit_menu(){

}

// Callbacks
void play() {
    // Whatever happens when play is called
    std::cout << "Play" << std::endl;
    game_screen = "game";
}

void highscore() {
    std::cout << "Highscore" << std::endl;
    game_screen = "highscore";
}

void quit() {
    std::cout << "Quit" << std::endl;
    game_screen = "quit";
}

// The graphics window class
void Ant_Window::make_grid() {
    for (int i = 0; i < WIDTH; i+=square_size) {
        for (int j = 0; j < HEIGHT; j+=square_size) {
            Point cor1(i,j);
            Point cor2(i+square_size,j);
            Point cor3(i+square_size,j+square_size);
            Point cor4(i,j+square_size);
            std::vector<TDT4102::Point> square{cor1,cor2,cor3,cor4};
            tiles.push_back(square);
        }
    }
}

void Ant_Window::draw_grid() {
    for (int i = 0; i < board_width; i++) {
        for (int j = 0; j < board_height; j++) {
            if (i%2 == j%2) {
                
            } else {

            }
        }
    }
}

// Constructor
Ant_Window::Ant_Window() : AnimationWindow{window_start_x, window_start_y, WIDTH, HEIGHT, window_name} {

}