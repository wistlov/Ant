#include "AnimationWindow.h"

// Here are all the variations of ants

// The main ant class. All other ants inherits from this one.
class Ants {
    // This will have:
    // Walking speed
    int ant_walkning = 768;
    int frame_step = 0;
    // Animation

    // Constructor
    Ants (std::string image_path_1, std::string image_path_2) {
        // Image and size
        TDT4102::Image Image1(image_path_1); // Defin the image of the ant
        TDT4102::Image Image2(image_path_2);
    }
    
    // Functions to mirror and change directions of the image
};

// This is the ant class for the ants that are simply animated
class Animated_Ant : public Ants {

};

// This is the ant class for the main ant that the player controlls
class Player_Ant : public Ants {

};

// This is the ant class for the ants that follow the Player_Ant. They act as the "body" in Snake. 
class Follower_Ant : public Ants {

};