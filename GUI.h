#pragma once

#include "std_lib_facilities.h"
#include "AnimationWindow.h"
#include "widgets/Button.h"
#include <iostream>



// Buttons
Button make_play_button(int posx, int posy, int width, int height, AnimationWindow& window);
Button make_highscore_button(int posx, int posy, int width, int height, AnimationWindow& window);
Button make_quit_button(int posx, int posy, int width, int height, AnimationWindow& window);


// Menu "Base"/Background
void menu_overall_background(int width, int height, AnimationWindow& window);

//Escape to main menu
void Esacpe_menu(AnimationWindow& window);
// Callbacks
// (These are functions that buttons can make happen when clicked)
void play(); 
void highscore(); 
void quit();