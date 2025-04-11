#pragma once

#include "std_lib_facilities.h"
#include "AnimationWindow.h"
#include "GUI.h"
#include "ant.h"
#include "highscore.h"
#include "music_and_sounds.h"
#include "food.h"
#include "resources.h"

void play_game();

extern std::vector<Animated_Ant> ant_list; // This houses the ants for the menu
extern std::vector<Cloud> cloud_list; // This houses the clouds for the menu
extern std::vector<Food> food_list; // This houses the food for the game
extern std::vector<Player_Ant> player_ant_list; // This houses the player ant(s?)

// functions to make lists
void make_menu_ants(std::vector<Animated_Ant>& ant_list, int num);
void make_menu_clouds(std::vector<Cloud>& cloud_list);
void make_food(std::vector<Food>& food_list);
void make_player_ant(std::vector<Player_Ant>& player_ant_list);
