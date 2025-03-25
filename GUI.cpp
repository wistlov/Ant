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


//Menu background for the play button and high score before staring the game

TDT4102::Image Left_ant1("Images/cute_ant.gif"); // Defin the image of the ant
TDT4102::Image Left_ant2("Images/cute_ant_move2.gif");

TDT4102::Image Right_ant1("Images/cute_ant_mirrored.gif"); 
TDT4102::Image Right_ant2("Images/cute_ant_move2_mirrored.gif");

TDT4102::Image Cloud("Images/cloud.png"); //Define the cloud image
TDT4102::Image Mountain("Images/mountain.png"); //Define the mountain image

int ant_walkning_left = 768;
int ant_walkning_right = 0;
int ant_walking_speed = 8;
int frame_step = 0;
int cloud_movement = 832; // Start x-postion for the cloud and the movement of it

// Makes the ANT text
TDT4102::Point location {295, 0}; //Start point of the text
std::string message = "ANT"; // what the text is
Color textColor = TDT4102::Color::dark_red;
int fontSize = 120; 
TDT4102::Font fontFace = TDT4102::Font::times_bold;

// This here is the menu function that runs when the menu is up
void menu_overall_background(int width, int height, AnimationWindow& window){

    //Background
    window.draw_rectangle(TDT4102::Point{0,0}, width, height,  Color::deep_skyblue);
    window.draw_rectangle(TDT4102::Point{0,600}, width, height, Color::sandy_brown);
    window.draw_rectangle(TDT4102::Point{0,700}, width, 60, Color::saddle_brown);
    window.draw_rectangle(TDT4102::Point{0,600}, width, 20, Color::lawn_green);
    
    window.draw_text(location, message, textColor, fontSize, fontFace); // Draws the message

    //clouds
    cloud_movement = cloud_movement - 2;
    window.draw_image(TDT4102::Point{cloud_movement,50}, Cloud, 200, 100);
    window.draw_image(TDT4102::Point{(cloud_movement-400),20}, Cloud, 300, 100);
    window.draw_image(TDT4102::Point{cloud_movement,0}, Cloud, 200, 100);
    window.draw_image(TDT4102::Point{(cloud_movement-600),100}, Cloud, 200, 100);

    //Mountain background
    window.draw_image(TDT4102::Point{0,200}, Mountain, 832, 400);
    

    //Ant stuff
    frame_step = frame_step + 1; //To change image
    ant_walkning_left = ant_walkning_left - ant_walking_speed; // Amounts of pixel the ants move each frame from the left
    ant_walkning_right = ant_walkning_right + ant_walking_speed; // Amounts of pixel the ants move each frame from the right

    TDT4102::Point ant_start_walk_left {ant_walkning_left,(600-48)}; //Start point for the left walking ant

    TDT4102::Point ant_start_walk_right {ant_walkning_right,(700)}; //Start point for the right walking ant

    if(frame_step % 2 == 0){
        window.draw_image(ant_start_walk_left, Left_ant1, 64, 64); //Draws the first and image

        window.draw_image(ant_start_walk_right, Right_ant1, 64, 64);
    }
    else {
        window.draw_image(ant_start_walk_left, Left_ant2, 64, 64); //Draws the second ant image walking left

        window.draw_image(ant_start_walk_right, Right_ant2, 64, 64); //Draws the second ant image walking right
    }

    window.wait_for(0.2);
    
}

void highscore_menu(){

}

void quit_menu(){

}
// Callbacks

//Defintion for the diffrent states the gae can be inn


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