#pragma once

#include "std_lib_facilities.h"
#include "AnimationWindow.h"

// Here are all the variations of ants

// The main ant class. All other ants inherits from this one.
class Ants {

    public:
        // Position on the grid
        std::vector<int> true_pos;

        // Position of the ant drawn on the screen
        TDT4102::Point drawn_pos;

        // The distance in units the ant has traveled from its true_pos
        double distance;

        // Walking speed (in the unit frames) (This is set to something that is a factor in the square size (64) based on difficulty)
        // Should work fine with 0.5, 1 or 2, but anything not fitting with 6 and 64 can cause issues. 6 because of the animation and 64 because of the square size. 
        double speed;

        // The direction the ant is facing. Possible: Left(1), Right(2), Up_Left(3), Up_Right(4), Down_Left(5), Down_Right(6)
        int direction;

        // This will save the last button the player pressed to change the direction of the ant. 
        std::string saved_direction;

        // An internal clock for each ant that can be used to know the time since an event for the specific ant. Counted in frames, where 60 is one second.
        // This will be used for the animation
        double internal_time;

        // Used to know if the ant is in animation fram 1 or 2.
        int animation_frame;

        // The current image the ant is supposed to be drawn as
        TDT4102::Image image;

        // Size of the image as well as each square
        int size;
        
    
        // Constructor
        Ants(int input_direction, double input_speed, std::vector<int> grid_position);
     
        // Functions
        int get_direction(); 
        int get_speed();
        double get_internal_time();

        void change_direction(std::string direction_change); // This changes the direction the ant is walking

        void update(TDT4102::AnimationWindow& window); // This updates all variables that may change each frame.

        void update_position(); // This updates the drawn_position based on the grid position (true_position),
        // as well as updating the grid position when the drawn_position has reached the appropriate distance (64).
        // When this change happens, the direction of the ant can be changed.
        // --- The update_position function is currently based on the Player_Ant. Can be modified to work for Follower_Ant as well.

        void update_animation(); // This will check to see if the ant should change it sprite in order to animate it. 
        // The ant will change its image every 6 units (pixels) walked.

};

// This is the ant class for the ants that are simply animated (Will be used for clouds as well)
class Animated_Ant : Ants {
    int start_pos = 768; // Where the ant starts
    public:
        Animated_Ant(int input_direction, double input_speed, std::vector<int> grid_position);
        //void update(); // This function will override the Ants update function so this does what its supposed to instead
};

// This is the ant class for the main ant that the player controlls
class Player_Ant : public Ants {
    void update_position(); 
};

// This is the ant class for the ants that follow the Player_Ant. They act as the "body" in Snake. 
class Follower_Ant : public Ants {

};

// images
extern TDT4102::Image Left1;
extern TDT4102::Image Left2;

extern TDT4102::Image Right1;
extern TDT4102::Image Right2;

extern TDT4102::Image Up1_Left;
extern TDT4102::Image Up2_Left;
extern TDT4102::Image Up1_Right;
extern TDT4102::Image Up2_Right;

extern TDT4102::Image Down1_Left;
extern TDT4102::Image Down2_Left;
extern TDT4102::Image Down1_Right;
extern TDT4102::Image Down2_Right;