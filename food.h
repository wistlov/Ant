#pragma once

#include <random>
#include "std_lib_facilities.h"
#include "AnimationWindow.h"
#include "random"
#include <cstdlib>

std::vector<int> generate_food_postion();
int food_on_board(int food);
int random_food();

class Food {

    public:
        // Position on the grid
        std::vector<int> true_pos;

        std::vector<TDT4102::Image> Images;

        // Position of the ant drawn on the screen
        TDT4102::Point drawn_pos;

        // The current image the ant is supposed to be drawn as
        TDT4102::Image image;

        // Size of the image as well as each square
        int size;
        
        void update(TDT4102::AnimationWindow& window); // This updates all variables that may change each frame.

        Food();

};

//Food images
extern TDT4102::Image Dragonfruit;
extern TDT4102::Image Strawberry;
extern TDT4102::Image Apple;
extern TDT4102::Image Tomato;
extern TDT4102::Image Chees;
extern TDT4102::Image Cookie;
extern TDT4102::Image Sushi;
extern TDT4102::Image Watermellon;