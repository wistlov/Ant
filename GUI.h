#pragma once

#include "std_lib_facilities.h"
#include "AnimationWindow.h"
#include "widgets/Button.h"
#include <iostream>
#include "game.h"

// Buttons
Button make_play_button(int posx, int posy, int width, int height);
void show_button(Button button, AnimationWindow window);

// Menu "Base"/Background
void menu_background(int height, int width, AnimationWindow& window);
void text_background(AnimationWindow& window);
void ant_background(AnimationWindow& window);
// Callbacks
// (These are functions that buttons can make happen when clicked)
void play(); 