#pragma once

#include "std_lib_facilities.h"
#include "AnimationWindow.h"
#include "GUI.h"
#include "ant.h"
#include "highscore.h"
#include "music_and_sounds.h"
#include "food.h"

// Making a global variable
extern std::string game_screen;
extern bool ants_moving;

void play_game();

void make_menu_ants(std::vector<Animated_Ant>& ant_list, int num);
void make_menu_clouds(std::vector<Cloud>& cloud_list);
