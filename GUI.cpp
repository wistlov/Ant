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

//Difficulty buttons

Button make_easy_play_button(int posx, int posy, int width, int height, AnimationWindow& window) {
    const TDT4102::Point buttonPosition {posx, posy};
    const unsigned int buttonWidth = width;
    const unsigned int buttonHeight = height;
    const string buttonLabel = "Easy";
    TDT4102::Button easy_play_button {buttonPosition, buttonWidth, buttonHeight, buttonLabel};
    easy_play_button.setButtonColor(TDT4102::Color::green);
    easy_play_button.setButtonColorHover(TDT4102::Color::lime_green);
    easy_play_button.setButtonColorActive(TDT4102::Color::dark_green);
    easy_play_button.setLabelColor(TDT4102::Color::white);
    easy_play_button.setCallback(easy); //This is what happens when the button is clicked.
    return easy_play_button;
}

Button make_normal_play_button(int posx, int posy, int width, int height, AnimationWindow& window) {
    const TDT4102::Point buttonPosition {posx, posy};
    const unsigned int buttonWidth = width;
    const unsigned int buttonHeight = height;
    const string buttonLabel = "Normal";
    TDT4102::Button normal_play_button {buttonPosition, buttonWidth, buttonHeight, buttonLabel};
    normal_play_button.setButtonColor(TDT4102::Color::royal_blue);
    normal_play_button.setButtonColorHover(TDT4102::Color::sky_blue);
    normal_play_button.setButtonColorActive(TDT4102::Color::slate_blue);
    normal_play_button.setLabelColor(TDT4102::Color::white);
    normal_play_button.setCallback(normal); //This is what happens when the button is clicked.
    return normal_play_button;
}

Button make_hard_play_button(int posx, int posy, int width, int height, AnimationWindow& window) {
    const TDT4102::Point buttonPosition {posx, posy};
    const unsigned int buttonWidth = width;
    const unsigned int buttonHeight = height;
    const string buttonLabel = "Hard";
    TDT4102::Button hard_play_button {buttonPosition, buttonWidth, buttonHeight, buttonLabel};
    hard_play_button.setButtonColor(TDT4102::Color::red);
    hard_play_button.setButtonColorHover(TDT4102::Color::orange_red);
    hard_play_button.setButtonColorActive(TDT4102::Color::dark_red);
    hard_play_button.setLabelColor(TDT4102::Color::white);
    hard_play_button.setCallback(hard); //This is what happens when the button is clicked.
    return hard_play_button;
}

Button make_resume_button(int posx, int posy, int width, int height, AnimationWindow& window) {
    const TDT4102::Point buttonPosition {posx, posy};
    const unsigned int buttonWidth = width;
    const unsigned int buttonHeight = height;
    const string buttonLabel = "Resume";
    TDT4102::Button resume_button {buttonPosition, buttonWidth, buttonHeight, buttonLabel};
    resume_button.setButtonColor(TDT4102::Color::red);
    resume_button.setButtonColorHover(TDT4102::Color::orange_red);
    resume_button.setButtonColorActive(TDT4102::Color::dark_red);
    resume_button.setLabelColor(TDT4102::Color::white);
    resume_button.setCallback(resume); //This is what happens when the button is clicked.
    return resume_button;
}

Button make_restart_button(int posx, int posy, int width, int height, AnimationWindow& window) {
    const TDT4102::Point buttonPosition {posx, posy};
    const unsigned int buttonWidth = width;
    const unsigned int buttonHeight = height;
    const string buttonLabel = "Restart";
    TDT4102::Button restart_button {buttonPosition, buttonWidth, buttonHeight, buttonLabel};
    restart_button.setButtonColor(TDT4102::Color::red);
    restart_button.setButtonColorHover(TDT4102::Color::orange_red);
    restart_button.setButtonColorActive(TDT4102::Color::dark_red);
    restart_button.setLabelColor(TDT4102::Color::white);
    restart_button.setCallback(restart); //This is what happens when the button is clicked.
    return restart_button;
}

Button make_main_menu_button(int posx, int posy, int width, int height, AnimationWindow& window) {
    const TDT4102::Point buttonPosition {posx, posy};
    const unsigned int buttonWidth = width;
    const unsigned int buttonHeight = height;
    const string buttonLabel = "Main Menu";
    TDT4102::Button main_menu_button {buttonPosition, buttonWidth, buttonHeight, buttonLabel};
    main_menu_button.setButtonColor(TDT4102::Color::red);
    main_menu_button.setButtonColorHover(TDT4102::Color::orange_red);
    main_menu_button.setButtonColorActive(TDT4102::Color::dark_red);
    main_menu_button.setLabelColor(TDT4102::Color::white);
    main_menu_button.setCallback(main_menu); //This is what happens when the button is clicked.
    return main_menu_button;
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
void Escape_menu(AnimationWindow& window) {
    bool Esc_key_is_pressed = window.is_key_down(KeyboardKey::ESCAPE);
    if(Esc_key_is_pressed) {
        game_screen = "menu";
    }}

void Escape_pause_menu(AnimationWindow& window) {
    bool Esc_key_is_pressed = window.is_key_down(KeyboardKey::ESCAPE);
    if(Esc_key_is_pressed) {
        game_screen = "paused";
    }}

void quit_menu(){

}

// Callbacks
void play() {
    // Whatever happens when play is called
    std::cout << "Play" << std::endl;
    game_screen = "difficulty";
}

void highscore() {
    std::cout << "Highscore" << std::endl;
    game_screen = "highscore";
}

void easy() {
    std::cout << "difficulty" << std::endl;
    player_ant_speed = 1.0;
    game_screen = "game";
}
void normal() {
    std::cout << "difficulty" << std::endl;
    player_ant_speed = 1.5;
    game_screen = "game";
}
void hard() {
    std::cout << "difficulty" << std::endl;
    player_ant_speed = 2.0;
    game_screen = "game";
}
void resume() {
    std::cout << "resume" << std::endl;
    game_screen = "game";
}
void restart() {
    std::cout << "restart" << std::endl;
    score = 1;
    game_screen = "game";
}
void main_menu() {
    std::cout << "main_menu" << std::endl;
    game_screen = "menu";
}
void quit() {
    std::cout << "Quit" << std::endl;
    game_screen = "quit";
}

//Function for when its game over
void game_over(AnimationWindow& win) {
    std::cout << "Game over" << std::endl;
    std::cout << "Score: "<< score << std::endl;
    game_screen = "highscore";
    win.draw_text(TDT4102::Point{248,200}, "GAME OVER", TDT4102::Color::yellow, 60, TDT4102::Font::times_bold);
    win.draw_text(TDT4102::Point{250,200}, "GAME OVER", TDT4102::Color::black, 60, TDT4102::Font::times_bold);
    win.draw_text(TDT4102::Point{50,300}, "Write your name in the terminal", TDT4102::Color::yellow, 60, TDT4102::Font::times_bold);
    win.draw_text(TDT4102::Point{52,300}, "Write your name in the terminal", TDT4102::Color::black, 60, TDT4102::Font::times_bold);
    win.next_frame();
    save_score(); 

    player_ant_list = {};
    follower_ant_list = {};
    food_list = {};

    make_player_ant(player_ant_list);
    make_food(food_list);
    score = 1;

    std::cout<<"Go back to the screen to see your score in the leaderboard"<<std::endl;
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
    counter = 0;
    for (int i = 0; i < board_width; i++) {
        for (int j = 0; j < board_height; j++) {
            if (i%2 == j%2) {
                draw_quad(tiles[counter][0], tiles[counter][1], tiles[counter][2], tiles[counter][3], Color::lawn_green);
            } else {
                draw_quad(tiles[counter][0], tiles[counter][1], tiles[counter][2], tiles[counter][3], Color::lime_green);
            }
        counter++;
        }
    }
}

// Constructor
Ant_Window::Ant_Window() : AnimationWindow{window_start_x, window_start_y, WIDTH, HEIGHT, window_name} {
    make_grid();
}

void Ant_Window::check_input() {
    // Left will be prioritized, then up, right and then down. In case multiple buttons are pressed at once.
    if (is_key_down(KeyboardKey::LEFT)) {
        button_input = "left";
    } else if (is_key_down(KeyboardKey::UP)) {
        button_input = "up";
    } else if (is_key_down(KeyboardKey::RIGHT)) {
        button_input = "right";
    } else if (is_key_down(KeyboardKey::DOWN)) {
        button_input = "down";
    }
}