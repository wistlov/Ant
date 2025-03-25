#include "AnimationWindow.h"

// Here are all the variations of ants

// The main ant class. All other ants inherits from this one.
class Ants {

    private:
        // Walking speed

        // The direction the ant is facing. Possible: Left(1), Right(2), Up_Left(3), Up_Right(4), Down_Left(5), Down_Right(6)
        int direction;

        // An internal clock for each ant that can be used to know the time since an event for the specific ant
        double internal_time; 

        // The current image the ant is supposed to be drawn as
        TDT4102::Image image;

    public:
        // Constructor
        Ants (int input_direction, TDT4102::Image input_image) {  
             // Decides which image to be used in the animation given a direction
            int frame_step = 0;

            // Starting image
            image = input_image;

            // Ant size (x*x), where x is the size
            int size = 64;

            // Sets the direction of the Ant
            direction = input_direction;
        }
    
    
        // Functions to mirror and change directions of the ant
        int get_direction(); // Returns the direction the ant is facing

        void change_direction(std::string direction); // This changes the direction the ant is walking
};


        // Images
        TDT4102::Image Left1("Images/cute_ant.gif");
        TDT4102::Image Left2("Images/cute_ant_move2.gif");

        TDT4102::Image Right1("Images/cute_ant_mirrored.gif");
        TDT4102::Image Right2("Images/cute_ant_move2_mirrored.gif");

        // Dont yet have the images for these so placeholders are used
        TDT4102::Image Up1_Left("Images/cute_ant_up1_left.gif");
        TDT4102::Image Up2_Left("Images/cute_ant_up2_left.gif");
        TDT4102::Image Up1_Right("Images/cute_ant_up1_right.gif");
        TDT4102::Image Up2_Right("Images/cute_ant_up2_right.gif");

        TDT4102::Image Down1_Left("Images/cute_ant_down1_left.gif");
        TDT4102::Image Down2_Left("Images/cute_ant_down2_left.gif");
        TDT4102::Image Down1_Right("Images/cute_ant_down1_right.gif");
        TDT4102::Image Down2_Right("Images/cute_ant_down2_right.gif");
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

