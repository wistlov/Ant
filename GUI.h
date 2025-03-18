#pragma once

#include "std_lib_facilities.h"
#include "AnimationWindow.h"
#include "widgets/Button.h"
#include <iostream>

// Menu "Base"/Background
void menu_background(int width, int height);

// Buttons
Button make_play_button(int posx, int posy, int width, int height);
void show_button(Button button, AnimationWindow window);

// Callbacks
// (These are functions that buttons can make happen when clicked)
void play(); 