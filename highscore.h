#pragma once

#include "std_lib_facilities.h"
#include "AnimationWindow.h"
#include "widgets/Button.h"
#include "ant.h"
#include <iostream>
#include "save_and_load.h"


void highscore_menu(int width, int height, AnimationWindow& window,std::vector<std::pair<std::string, int>> scores);
void difficulty_menu(int width, int height, AnimationWindow& window);
void control_menu(int width, int height, AnimationWindow& window);
void paused_menu(int width, int height, AnimationWindow& window);
