#pragma once

#include <random>
#include "std_lib_facilities.h"
#include "AnimationWindow.h"
#include "random"
#include <cstdlib>
#include "ant.h"
#include "image.h"

std::vector<int> generate_food_postion();
int food_on_board(int food);
int random_food();

class Food {

    public:
        // Position on the grid
        std::vector<int> true_pos;

        // List of images
        std::vector<TDT4102::Image> Images{Apple, Chees};
        int food_num;

        // Position of the ant drawn on the screen
        TDT4102::Point drawn_pos;

        // The current image the ant is supposed to be drawn as
        TDT4102::Image image;

        // Size of the image as well as each square
        int size;
        
        void update(TDT4102::AnimationWindow& window); // This updates all variables that may change each frame.

        Food();

        int random_food();



};



