#pragma once

#include <random>
#include "std_lib_facilities.h"
#include "AnimationWindow.h"
#include "random"
#include <cstdlib>
#include "ant.h"
#include "resources.h"

// This now returns a GridPos instead of std::vector<int>
GridPos generate_food_postion();

class Food {

public:
    // Position on the grid
    GridPos true_pos;

    // List of images
    std::vector<TDT4102::Image> Images{Spagheti, Bowl, Hamburger};
    int food_num;

    // Position of the food drawn on the screen
    TDT4102::Point drawn_pos;

        // The current image the ant is supposed to be drawn as
        TDT4102::Image image;

        // Size of the image as well as each square + food animation 
        int size;
        double food_puls;
        int food_control;

    // Constructor
    Food();

    // Functions
    int random_food();
    void update(TDT4102::AnimationWindow& window); // This updates all variables that may change each frame.
    void new_position(); // Changes position when needed

    // Type of food, aka worth
    // Hamburger = 3
    // Bowl = 2
    // Spagetti = 1
    int food_type;
};
