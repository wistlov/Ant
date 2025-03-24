#include "game.h"

// Global variables
string game_screen = "menu";// setts which state the game is in


void play_game(AnimationWindow win) {

    while (!win.should_close()) {  //Makes it so the game stops when the window closes
        //The game
        while(game_screen == "menu"){
            menu_overall_background(832, 832, win);
            //Button stuff
            //show_button(play_button, win);   //This didnt work but the code below does the same thing
            
            win.wait_for_close();
        }

        // This launches the main game
        while(game_screen == "game"){
            // Currently, the game window closes and restarts in order to get by the wait_for_close() in the loop above. This is not a good long term solution.
            AnimationWindow win{400, 25, 832, 832, "Ant"};
            Grid(13, 13, 832, 832, win);

            win.wait_for_close(); //When just outside of while function it wont close
            win.next_frame();
        }
        
    win.wait_for_close();
    win.next_frame();
    }
}