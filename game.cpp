#include "game.h"

// Some global lists
std::vector<Animated_Ant> ant_list; // This houses the ants for the menu
std::vector<Cloud> cloud_list; // This houses the clouds for the menu
std::vector<Food> food_list; // This houses the food for the game
std::vector<Player_Ant> player_ant_list; // This houses the player ant(s?)

// Functions to make global lists -------------------------------------------------------

// This function generates the ants for the main menu
void make_menu_ants(std::vector<Animated_Ant>& ant_list, int num) {
    for (int i = 0; i < num; i++) {
        Animated_Ant ant_right(1, 0.2, GridPos{14+i, 11});
        Animated_Ant ant_left(2, 0.2, GridPos{-2-i, 9});
        ant_list.push_back(ant_right);
        ant_list.push_back(ant_left);
    }
}

// This function generates the clouds for the main menu
void make_menu_clouds(std::vector<Cloud>& cloud_list) {
    cloud_list.push_back(Cloud(1, 0.1, GridPos{13, 2}));
    cloud_list.push_back(Cloud(1, 0.2, GridPos{4, 6}));
    cloud_list.push_back(Cloud(1, 0.15, GridPos{7, 4}));
    cloud_list.push_back(Cloud(1, 0.05, GridPos{11, 5}));
}

// This function generates the food for the main game
void make_food(std::vector<Food>& food_list) {
    Food food;
    srand(time(0));
    food_list.push_back(food);
}

// This function makes the player ant
void make_player_ant(std::vector<Player_Ant>& player_ant_list) {
    player_ant_list.push_back(Player_Ant(1, player_ant_speed, GridPos{6, 6}));
}

void make_follower_ant(std::vector<Follower_Ant>& follower_ant_list, GridPos pos, int direction) {
    follower_ant_list.push_back(Follower_Ant(direction, player_ant_speed, pos, 0));
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

    Button easy_play_button = make_easy_play_button(60, 500, 200, 100, win);
    win.add(easy_play_button); // This adds the button, naturally

    Button normal_play_button = make_normal_play_button(325, 500, 200, 100, win);
    win.add(normal_play_button); // This adds the button, naturally

    Button hard_play_button = make_hard_play_button(590, 500, 200, 100, win);
    win.add(hard_play_button); // This adds the button, naturally

    Button resume_button = make_resume_button(66, 280, 200, 100, win);
    win.add(resume_button); // This adds the button, naturally

    Button restart_button = make_restart_button(320, 280, 200, 100, win);
    win.add(restart_button); // This adds the button, naturally

    Button main_menu_button = make_main_menu_button(576, 280, 200, 100, win);
    win.add(main_menu_button); // This adds the button, naturally

    // Here are the animated ants added
    make_menu_ants(ant_list, 16);

    // Here are the clouds added
    make_menu_clouds(cloud_list);
    // Here the food is added
    make_food(food_list);

    // Here the player is added
    make_player_ant(player_ant_list);

    // Here the follower ants are added
    //make_follower_ant(follower_ant_list, GridPos{7, 6}, 1);

    while (!win.should_close()) {

        if(game_screen == "menu") {
            win.draw_rectangle(TDT4102::Point{0,0}, 832, 832,  Color::deep_skyblue);

            for (int i = 0; i < cloud_list.size(); i++) {
                cloud_list.at(i).update(win);
            }

            menu_overall_background(832, 832, win);

            for (int i = 0; i < ant_list.size(); i++) {
                ant_list.at(i).update(win);
            }

            play_button.setVisible(true);
            highscore_button.setVisible(true);
            quit_button.setVisible(true);
            easy_play_button.setVisible(false);
            normal_play_button.setVisible(false);
            hard_play_button.setVisible(false);
            resume_button.setVisible(false);
            restart_button.setVisible(false);
            main_menu_button.setVisible(false);
        }

        else if(game_screen == "difficulty"){
            difficulty_menu(832, 832, win);
            play_button.setVisible(false);
            highscore_button.setVisible(false);
            quit_button.setVisible(false);
            easy_play_button.setVisible(true);
            normal_play_button.setVisible(true);
            hard_play_button.setVisible(true);
            resume_button.setVisible(false);
            restart_button.setVisible(false);
            main_menu_button.setVisible(false);
            Escape_menu(win);
        }

        else if (game_screen == "game") {

            win.draw_grid();
            win.check_input();

            for (int i = 0; i < food_list.size(); i++) {
                food_list.at(i).update(win);
            }

            for (int i = 0; i < player_ant_list.size(); i++) {
                player_ant_list.at(i).update(win);
                player_ant_list.at(i).speed = player_ant_speed;
                if (!follower_ant_list.empty()) {
                    follower_ant_list.at(0).set_destination(player_ant_list.at(i).true_pos);
                }
                if (player_ant_list.at(i).check_wall_collision()) {
                    game_over();
                    win.close(); //-----------------NB!-------------TEMPORARY SOLUTION-----------------------------------<<<<<<<<<<<<<<<<<<<<<<<<<
                }

                if (player_ant_list.at(i).check_for_food(food_list.at(0).true_pos)) {
                    food_list.erase(food_list.begin());
                    score += 1;
                    if (!follower_ant_list.empty()) {
                        make_follower_ant(follower_ant_list, follower_ant_list.back().true_pos, follower_ant_list.back().direction);
                    } else {
                        make_follower_ant(follower_ant_list, player_ant_list.back().true_pos, player_ant_list.back().direction);
                    }
                    make_food(food_list);
                }
            }
            for (int i = 0; i < follower_ant_list.size(); i++) {
                follower_ant_list.at(i).update(win);
                follower_ant_list.at(i).speed = player_ant_speed;
                if (i > 0) {
                    follower_ant_list.at(i).set_destination(follower_ant_list.at(i-1).true_pos);
                    follower_ant_list.at(i).speed = player_ant_speed;
                }
                if ((follower_ant_list.at(i).true_pos.x == player_ant_list.at(0).true_pos.x) && (follower_ant_list.at(i).true_pos.y == player_ant_list.at(0).true_pos.y) && i > 0) {
                    game_over();
                    win.close(); //-----------------NB!-------------TEMPORARY SOLUTION-----------------------------------<<<<<<<<<<<<<<<<<<<<<<<<<
                }
            }

            //------------Draws a cute ant and the score to the right of it, in the top left cornor
            win.draw_image(TDT4102::Point{0,0}, Cute_ant, 32, 32);
            win.draw_text(TDT4102::Point{32, 0}, std::to_string(score), TDT4102::Color::black, 24, TDT4102::Font::courier_bold_italic);

            //--------------------------------------------
            play_button.setVisible(false); // Hides the button while the game is running
            highscore_button.setVisible(false);
            quit_button.setVisible(false);
            easy_play_button.setVisible(false);
            normal_play_button.setVisible(false);
            hard_play_button.setVisible(false);
            resume_button.setVisible(false);
            restart_button.setVisible(false);
            main_menu_button.setVisible(false);
            Escape_pause_menu(win);
        }

        else if(game_screen == "paused"){
            win.draw_grid();
            paused_menu(832, 832, win);
            play_button.setVisible(false);
            highscore_button.setVisible(false);
            quit_button.setVisible(false);
            easy_play_button.setVisible(false);
            normal_play_button.setVisible(false);
            hard_play_button.setVisible(false);
            resume_button.setVisible(true);
            restart_button.setVisible(true);
            main_menu_button.setVisible(true);
        }

        else if (game_screen == "highscore"){
            highscore_menu(832, 832, win);
            background_music();

            play_button.setVisible(false);
            highscore_button.setVisible(false);
            quit_button.setVisible(false);
            easy_play_button.setVisible(false);
            normal_play_button.setVisible(false);
            hard_play_button.setVisible(false);
            resume_button.setVisible(false);
            restart_button.setVisible(false);
            main_menu_button.setVisible(false);
            Escape_menu(win);
        }

        else if (game_screen == "quit"){
            win.draw_rectangle(TDT4102::Point{0, 0}, 832, 832, TDT4102::Color::white);
            win.draw_text(TDT4102::Point{0,200}, "ARE YOU SURE?", TDT4102::Color::black, 100, TDT4102::Font::times_bold);
            play_button.setVisible(false);
            highscore_button.setVisible(false);
            quit_button.setVisible(false);
            easy_play_button.setVisible(false);
            normal_play_button.setVisible(false);
            hard_play_button.setVisible(false);
            resume_button.setVisible(false);
            restart_button.setVisible(false);
            main_menu_button.setVisible(false);
            Escape_menu(win);
        }

        win.next_frame();
    }
}
