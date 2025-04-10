#pragma once

#include "std_lib_facilities.h"
#include "AnimationWindow.h"
#include "resources.h"

class Follower_Ant; // forward declaration so that Player_Ant and the list below knows about it for its functions
extern std::vector<Follower_Ant> follower_ant_list; // This houses the follower ants

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
class Animated_Ant : public Ants {
    private:
        int start_true_pos; // Where the ant starts
    public:
        Animated_Ant(int input_direction, double input_speed, std::vector<int> grid_position);
        void update(TDT4102::AnimationWindow& window); // This function will override the Ants update function so this does what its supposed to instead

        // A function to teleport the ant back to its starting position when it exceeds a certain length.
        void check_for_teleport();
        // Need a function that destroys ants that touches the mouse pointer
};

// This is the ant class for the main ant that the player controlls
class Player_Ant : public Ants {
    public:
        Player_Ant(int input_direction, double input_speed, std::vector<int> grid_position);
        void update_position(); 
        void check_input();
        void update(AnimationWindow& window);

};

// This is the ant class for the ants that follow the Player_Ant. They act as the "body" in Snake. 
class Follower_Ant : public Player_Ant {
    private:
        int ant_id;
    public:
        Follower_Ant(int input_direction, double input_speed, std::vector<int> grid_position, int input_id);
        
        // To make sure the follower ant doesnt start moving until its supposed to
        bool move = false;

        // Function for setting a new destination
        void set_destination(const std::vector<int>& pos);

        // The update function needs to be changed as well so it doesnt take in button inputs
        void update(AnimationWindow& window);

        // It has a modified update position function so it doesnt change direction when its not supposed to
        void update_position();
};

// This is a class for the clouds. Clouds are Ants, that should be obvious.
class Cloud : public Animated_Ant {
    private:
        int start_true_pos_x;
        int start_true_pos_y;
    public:
        Cloud(int input_direction, double input_speed, std::vector<int> grid_position);
        void update(TDT4102::AnimationWindow& window);
        void update_animation();
};
