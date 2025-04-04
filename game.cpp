#include "game.h"

// Global variables
std::string game_screen = "menu";// setts which state the game is in

std::vector<Animated_Ant> ant_list; // This houses the ants for the menu
// This function generates the ants for the main menu
void make_menu_ants(std::vector<Animated_Ant>& ant_list, int num) {
    for (int i = 0; i < num; i++) {
        Animated_Ant ant_right(1,0.2,std::vector<int> {13+i,11});
        Animated_Ant ant_left(2,0.2,std::vector<int> {-1-i,9});
        ant_list.push_back(ant_right);
        ant_list.push_back(ant_left);
    }
}

void play_game(AnimationWindow& win) {
    // The game

    // The stuff before the while loop is what is initiated before the game begins.
    Button play_button = make_play_button(266, 150, 300, 100, win);
    win.add(play_button); // This adds the button, naturally

    Button highscore_button = make_highscore_button(266, 275, 300, 100, win);
    win.add(highscore_button); // This adds the button, naturally

    Button quit_button = make_quit_button(266, 400, 300, 100, win);
    win.add(quit_button); // This adds the button, naturally

    // Here are the animated ants added
    make_menu_ants(ant_list, 13);


    while (!win.should_close()) {  //Makes it so the game stops when the window closes
        
        if(game_screen == "menu") { //This is the code that will be run while the game is in the menu.
            menu_overall_background(832, 832, win);

            // update menu ants
            for (int i = 0; i < ant_list.size(); i++) {
                ant_list.at(i).update(win);
            }

            play_button.setVisible(true); // Shows the button while the menu is active
            highscore_button.setVisible(true);
            quit_button.setVisible(true);
        }

        // This is what runs when the play button has been clicked. In theory.
        else if (game_screen == "game") { 
            // This clears the screen. 
            win.draw_rectangle(TDT4102::Point{0, 0}, 832, 832, TDT4102::Color::white);

            Grid(13, 13, 832, 832, win);

            play_button.setVisible(false); // Hides the button while the game is running
            highscore_button.setVisible(false);
            quit_button.setVisible(false);
            Esacpe_menu(win);
        }

        //This is what runs if the highscore button has been hit
        else if (game_screen == "highscore"){
            highscore_menu(832, 832, win);
            background_music();

            play_button.setVisible(false);
            highscore_button.setVisible(false);
            quit_button.setVisible(false);
            Esacpe_menu(win);
        }

        else if (game_screen == "quit"){
            win.draw_rectangle(TDT4102::Point{0, 0}, 832, 832, TDT4102::Color::white);
            win.draw_text(TDT4102::Point{0,200}, "ARE YOU SURE?", TDT4102::Color::black, 100, TDT4102::Font::times_bold);
            play_button.setVisible(false);
            highscore_button.setVisible(false);
            quit_button.setVisible(false);
            Esacpe_menu(win);
        }

        win.next_frame(); // Continues to the next frame
    }
}