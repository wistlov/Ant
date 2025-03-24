#include "AnimationWindow.h"

// Here are all the variations of ants

// The main ant class. All other ants inherits from this one.
class Ants {
    // This will have:
    // Walking speed
    int ant_walkning = 768;
    int frame_step = 0;
    // Animation
    // Image and size
    TDT4102::Image Image1("Images/cute_ant.gif"); // Defin the image of the ant
    TDT4102::Image Image2("Images/cute_ant_move2.gif");
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