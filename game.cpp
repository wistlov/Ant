#include "game.h"

// Global variables
string game_screen = "menu";// setts which state the game is in


void play_game(AnimationWindow win) {

    while (!win.should_close()) {  //Makes it so the game stops when the window closes
        //The game
        while(game_screen == "menu"){
            menu_background(832, 832, win); //Gets the function for the menu design
            text_background(win);
            //Button stuff
            Button play_button = make_play_button(225, 150, 300, 100, win);
            //show_button(play_button, win);   //This didnt work but the code below does the same thing
            win.add(play_button); //This is what makes the button show up
            
            //win.draw_line(TDT4102::Point{0,0},TDT4102::Point{750,750}, Color::black);
            win.wait_for_close();
        }

        // This launches the main game
        while(game_screen == "game"){
            AnimationWindow win{400, 25, 832, 832, "Ant"};
            Grid(13, 13, 832, 832, win);

            win.wait_for_close(); //When just outside of while function it wont close
            win.next_frame();
        }
        
    win.wait_for_close();
    win.next_frame();
    }
}