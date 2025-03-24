#pragma once

#include "std_lib_facilities.h"
#include "AnimationWindow.h"
#include "widgets/Button.h"
#include <iostream>
#include "game.h"

// Buttons
Button make_play_button(int posx, int posy, int width, int height, AnimationWindow& window);
void show_button(Button button, AnimationWindow& window);

// Menu "Base"/Background
void menu_overall_background(int width, int height, AnimationWindow& window);
// Callbacks
// (These are functions that buttons can make happen when clicked)
void play(); 