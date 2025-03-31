#pragma once

#include "std_lib_facilities.h"
#include "AnimationWindow.h"
#include "GUI.h"
#include "grid.h"
#include "ant.h"

// Making a global variable
extern std::string game_screen;

void play_game(AnimationWindow& win);

void make_menu_ants(std::vector<Ants>& ant_list, int num);
