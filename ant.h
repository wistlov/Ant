#include "AnimationWindow.h"

// Here are all the variations of ants

// The main ant class. All other ants inherits from this one.
class Ants {

    private:
        // Walking speed (in the unit frames)
        int speed;

        // The direction the ant is facing. Possible: Left(1), Right(2), Up_Left(3), Up_Right(4), Down_Left(5), Down_Right(6)
        int direction;

        // An internal clock for each ant that can be used to know the time since an event for the specific ant. Counted in frames, where 60 is one second.
        double internal_time;
        
        // The time between each animation frame  (Confirmed that AnimationWindow has 60 fps. Hence why one second is 60 frames)
        double animation_duration;

        // The current image the ant is supposed to be drawn as
        TDT4102::Image image;

    public:
        // Constructor
        Ants (int input_direction, TDT4102::Image input_image, int input_speed) {  
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
            int size = 64; // Ant size (x*x), where x is the size
            direction = input_direction; // Sets the direction of the Ant
            speed = input_speed; // Sets the starting speed of the Ant
        }
    
        // Functions
        int get_direction(); // Returns the direction the ant is facing

        void change_direction(std::string direction); // This changes the direction the ant is walking

        void update(); // This updates all variables that may change each frame.

};

// This is the ant class for the ants that are simply animated
class Animated_Ant : public Ants {
    int start_pos = 768; // Where the ant starts
    
};

// This is the ant class for the main ant that the player controlls
class Player_Ant : public Ants {

};

// This is the ant class for the ants that follow the Player_Ant. They act as the "body" in Snake. 
class Follower_Ant : public Ants {

};

