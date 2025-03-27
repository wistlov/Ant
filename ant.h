#include "AnimationWindow.h"

// Here are all the variations of ants

// The main ant class. All other ants inherits from this one.
class Ants : public TDT4102::AnimationWindow {

    private:
        // Position on the grid
        std::vector<int> true_pos;

        // Position of the ant drawn on the screen
        TDT4102::Point drawn_pos;

        // The distance in units the ant has traveled from its true_pos
        double distance;

        // Walking speed (in the unit frames) (This is set to something that is a factor in the square size (64) based on difficulty)
        // Should work fine with 0.5, 1 or 2, but anything not fitting with 6 and 64 can cause issues. 6 because of the animation and 64 because of the square size. 
        int speed;

        // The direction the ant is facing. Possible: Left(1), Right(2), Up_Left(3), Up_Right(4), Down_Left(5), Down_Right(6)
        int direction;

        // This will save the last button the player pressed to change the direction of the ant. 
        std::string saved_direction;

        // An internal clock for each ant that can be used to know the time since an event for the specific ant. Counted in frames, where 60 is one second.
        // This will be used for the animation
        double internal_time;
        
        // The time between each animation frame  (Confirmed that AnimationWindow has 60 fps. Hence why one second is 60 frames)
        double animation_duration;

        // The current image the ant is supposed to be drawn as
        TDT4102::Image image;

    public:
        // Constructor
        Ants (int input_direction, TDT4102::Image input_image, int input_speed, std::vector<int> grid_position) {
             // Decides which image to be used in the animation given a direction
            int frame_step = 0;

            // Images
            TDT4102::Image Left1("Images/cute_ant.gif");
            TDT4102::Image Left2("Images/cute_ant_move2.gif");

            TDT4102::Image Right1("Images/cute_ant_mirrored.gif");
            TDT4102::Image Right2("Images/cute_ant_move2_mirrored.gif");

            TDT4102::Image Up1_Left("Images/cute_ant_up1_left.gif");
            TDT4102::Image Up2_Left("Images/cute_ant_up2_left.gif");
            TDT4102::Image Up1_Right("Images/cute_ant_up1_right.gif");
            TDT4102::Image Up2_Right("Images/cute_ant_up2_right.gif");

            TDT4102::Image Down1_Left("Images/cute_ant_down1_left.gif");
            TDT4102::Image Down2_Left("Images/cute_ant_down2_left.gif");
            TDT4102::Image Down1_Right("Images/cute_ant_down1_right.gif");
            TDT4102::Image Down2_Right("Images/cute_ant_down2_right.gif");

            // Variables
            image = input_image; // Starting image
            int size = 64; // Ant size (x*x), where x is the size. This is also the size of a grid square. If that is not the case, the code will not work.
            direction = input_direction; // Sets the direction of the Ant
            speed = input_speed; // Sets the starting speed of the Ant
            true_pos = grid_position; // Sets the starting grid position
            distance = 0.0;
            // The drawn_pos does not need to be given a number as this should be calculated based on its true_pos and speed.
        }
     
        // Functions
        int get_direction(Ants ant); 
        int get_speed(Ants ant);
        double get_internal_time(Ants ant);

        void change_direction(Ants ant, std::string direction_change); // This changes the direction the ant is walking

        void update(Ants ant); // This updates all variables that may change each frame.

        void update_position(Ants ant); // This updates the drawn_position based on the grid position (true_position),
        // as well as updating the grid position when the drawn_position has reached the appropriate distance (64).
        // When this change happens, the direction of the ant can be changed.

        void update_animation(Ants ant); // This will check to see if the ant should change it sprite in order to animate it. 
        // The ant will change its image every 6 units (pixels) walked.

};

// This is the ant class for the ants that are simply animated (Will be used for clouds as well)
class Animated_Ant : public Ants {
    int start_pos = 768; // Where the ant starts
    
};

// This is the ant class for the main ant that the player controlls
class Player_Ant : public Ants {

};

// This is the ant class for the ants that follow the Player_Ant. They act as the "body" in Snake. 
class Follower_Ant : public Ants {

};

