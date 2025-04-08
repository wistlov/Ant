#include "game.h"

// ants_moving is necessary for the game to only start when the player wants it to.

std::vector<Animated_Ant> ant_list; // This houses the ants for the menu
std::vector<Cloud> cloud_list; // This houses the clouds for the menu
std::vector<Food> food_list; // This houses the food for the game
std::vector<Player_Ant> player_ant_list; // This houses the player ant(s?)

// This function generates the ants for the main menu
void make_menu_ants(std::vector<Animated_Ant>& ant_list, int num) {
    for (int i = 0; i < num; i++) {
        Animated_Ant ant_right(1,0.2,std::vector<int> {14+i,11});
        Animated_Ant ant_left(2,0.2,std::vector<int> {-2-i,9});
        ant_list.push_back(ant_right);
        ant_list.push_back(ant_left);
    }
}
// This function generates the clouds for the main menu
void make_menu_clouds(std::vector<Cloud>& cloud_list) {
    Cloud cloud0(1,0.1,std::vector<int> {13,2}); // The grid position is the input (0-12,0-12)
    cloud_list.push_back(cloud0);
    Cloud cloud1(1,0.2,std::vector<int> {4,6});
    cloud_list.push_back(cloud1);
    Cloud cloud2(1,0.15,std::vector<int> {7,4});
    cloud_list.push_back(cloud2);
    Cloud cloud3(1,0.05,std::vector<int> {11,5});
    cloud_list.push_back(cloud3);
}

//This function generates the food for the main game
void make_food(std::vector<Food>& food_list) {
    Food food;
    srand(time(0));
    food_list.push_back(food);
}
// This function makes the player ant
void make_player_ant(std::vector<Player_Ant>& player_ant_list) {
    Player_Ant player(1,player_ant_speed,std::vector<int> {6,6});
    player_ant_list.push_back(player);
}

void play_game() {
    // The game
    // This will make the GUI elements
    Ant_Window win;

    // The stuff before the while loop is what is initiated before the game begins.
    Button play_button = make_play_button(266, 150, 300, 100, win);
    win.add(play_button); // This adds the button, naturally

    Button highscore_button = make_highscore_button(266, 275, 300, 100, win);
    win.add(highscore_button); // This adds the button, naturally

    Button quit_button = make_quit_button(266, 400, 300, 100, win);
    win.add(quit_button); // This adds the button, naturally

    // Here are the animated ants added
    make_menu_ants(ant_list, 16);

    // Here are the clouds added
    make_menu_clouds(cloud_list);

    // Here the food is added
    make_food(food_list);

    // Here the player is added
    make_player_ant(player_ant_list);
    
    while (!win.should_close()) {  //Makes it so the game stops when the window closes
        
        if(game_screen == "menu") { //This is the code that will be run while the game is in the menu.
            // Drawing the sky first so it is on the bottom layer
            win.draw_rectangle(TDT4102::Point{0,0}, 832, 832,  Color::deep_skyblue);

            // update menu clouds (This is done before the rest of the background so the clouds are behind everything else)
            for (int i = 0; i < cloud_list.size(); i++) {
                cloud_list.at(i).update(win);
            }

            menu_overall_background(832, 832, win); // This code makes all of the background in the menu appear. (All that are not buttons)

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

            win.draw_grid();
            win.check_input(); // Checks for button inputs
            
            // update food
            for (int i = 0; i < food_list.size(); i++) {
                food_list.at(i).update(win);
            }

 
          

            //--------------------------------------------

            for (int i = 0; i < player_ant_list.size(); i++) {
                player_ant_list.at(i).update(win);
            }



            //--------------------------------------------
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