#include "ant.h"

//--------------------------------------------------------------------------------//
// Constructor for Ants
Ants::Ants (int input_direction, double input_speed, std::vector<int> grid_position) {
    // Decides which image to be used in the animation given a direction
   int frame_step = 0;

   // Variables
   size = 64; // Ant size (x*x), where x is the size. This is also the size of a grid square. If that is not the case, the code will not work.
   direction = input_direction; // Sets the direction of the Ant
   speed = input_speed; // Sets the starting speed of the Ant
   true_pos = grid_position; // Sets the starting grid position
   distance = 0.0; // Sets the distance for the true_pos the ant is.
   animation_frame = 0; // Sets which fram the ant's animation starts at
   // The drawn_pos does not need to be given a number as this should be calculated based on its true_pos, distance and speed.

   // Set initial image
   if (direction == 1) image = Left1;
   else if (direction == 2) image = Right1;
   else if (direction == 3) image = Up1_Left;
   else if (direction == 4) image = Up1_Right;
   else if (direction == 5) image = Down1_Left;
   else if (direction == 6) image = Down1_Right;   
}

// Functions for Ants
// Get functions
int Ants::get_direction() {
    return direction;
}

int Ants::get_speed() {
    return speed;
}

double Ants::get_internal_time() {
    return internal_time;
}

// direction: Left(1), Right(2), Up_Left(3), Up_Right(4), Down_Left(5), Down_Right(6)
// direction_change: left, right, up, down
void Ants::change_direction(std::string direction_change) {
    if (direction == 1) {
        if (direction_change == "up") {
            direction = 3;
        } else if (direction_change == "down") {
            direction = 5;
        }
    } else if (direction == 2) {
        if (direction_change == "up") {
            direction = 4;
        } else if (direction_change == "down") {
            direction = 6;
        }
    } else if (direction == 3 || direction == 4) {
        if (direction_change == "left") {
            direction = 1;
        } else if (direction_change == "right") {
            direction = 2;
        }
    } else if (direction == 5 || direction == 6) {
        if (direction_change == "left") {
            direction = 1;
        } else if (direction_change == "right") {
            direction = 2;
        }
    } 
}


void Ants::update_position() {
    if (direction == 1) { // Left
        drawn_pos.x -= speed;
        distance += speed;
        drawn_pos.x = true_pos.at(0)*size - distance;
        drawn_pos.y = true_pos.at(1)*size;
        // The lines above updates the visualized position of the ant.

        if (distance >= size) { // This happens when an ant reaches the center of a square.
            true_pos.at(0) -= 1;
            distance = 0;
            drawn_pos.x = true_pos.at(0)*size;

            change_direction(saved_direction); // The ant is only allowed to change direction when at the center of a square
        }

    } else if (direction == 2) { // Right
        drawn_pos.x += speed;
        distance += speed;
        drawn_pos.x = true_pos.at(0)*size + distance;
        drawn_pos.y = true_pos.at(1)*size;

        if (distance >= size) { // This happens when an ant reaches the center of a square.
            true_pos.at(0) += 1;
            distance = 0;
            drawn_pos.x = true_pos.at(0)*size;

            change_direction(saved_direction); // The ant is only allowed to change direction when at the center of a square
        }

    } else if (direction == 3 || direction == 4) { // Up
        drawn_pos.y -= speed;
        distance += speed;
        drawn_pos.y = true_pos.at(1)*size - distance;
        drawn_pos.y = true_pos.at(1)*size;
        // The lines above updates the visualized position of the ant.

        if (distance >= size) { // This happens when an ant reaches the center of a square.
            true_pos.at(1) -= 1;
            distance = 0;
            drawn_pos.y = true_pos.at(1)*size;

            change_direction(saved_direction); // The ant is only allowed to change direction when at the center of a square
        }
        
    } else if (direction == 5 || direction == 6) { // Down
        drawn_pos.y += speed;
        distance += speed;
        drawn_pos.y = true_pos.at(1)*size + distance;
        drawn_pos.y = true_pos.at(1)*size;
        // The lines above updates the visualized position of the ant.

        if (distance >= size) { // This happens when an ant reaches the center of a square.
            true_pos.at(1) += 1;
            distance = 0;
            drawn_pos.y = true_pos.at(1)*size;

            change_direction(saved_direction); // The ant is only allowed to change direction when at the center of a square
        }
    } 
}


// This functions animates the ant
void Ants::update_animation() {
    internal_time += 1*speed;
    if (internal_time >= 12) {
        internal_time = 0;
        if (direction == 1) { // Left
            if (animation_frame == 0) {
                image = Left2;
                animation_frame = 1;
            } else {
                image = Left1;
                animation_frame = 0;
            }
        } else if (direction == 2) { // Right
            if (animation_frame == 0) {
                image = Right2;
                animation_frame = 1;
            } else {
                image = Right1;
                animation_frame = 0;
            }
        } else if (direction == 3) { // Up Left
            if (animation_frame == 0) {
                image = Up2_Left;
                animation_frame = 1;
            } else {
                image = Up1_Left;
                animation_frame = 0;
            }
        } else if (direction == 4) { // Up Right
            if (animation_frame == 0) {
                image = Up2_Right;
                animation_frame = 1;
            } else {
                image = Up1_Right;
                animation_frame = 0;
            }
        } else if (direction == 5) { // Down Left
            if (animation_frame == 0) {
                image = Down2_Left;
                animation_frame = 1;
            } else {
                image = Down1_Left;
                animation_frame = 0;
            }
        } else if (direction == 6) { // Down Right
            if (animation_frame == 0) {
                image = Down2_Right;
                animation_frame = 1;
            } else {
                image = Down1_Right;
                animation_frame = 0;
            }
        }
    }
}

// This function is the one called on for all Ants. It decides what happens to the ant each frame.
void Ants::update(TDT4102::AnimationWindow& window) {
    update_position();
    update_animation();
    window.draw_image(drawn_pos, image, size, size);
}

// Ant Images 
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
//----------------------------------------------------------------------------------------------------//

// Animated_ant
// Constructor for Animated_Ant
Animated_Ant::Animated_Ant (int input_direction, double input_speed, std::vector<int> grid_position) : Ants(input_direction, input_speed, grid_position) {
    // Hope all this is covered in Ants. 
    start_true_pos = grid_position.at(0); // This stores where the ant started for use later
}


void Animated_Ant::check_for_teleport() {
    if (direction == 1) {
         if (true_pos.at(0) < -1) {
            true_pos.at(0) = 14;
         }
    } else {
        if (true_pos.at(0) > 14) {
            true_pos.at(0) = -1;
        }
    }
}

// Animated Ant overrides the update function of Ants for its own purposes
void Animated_Ant::update(TDT4102::AnimationWindow& window) {
    update_position();
    check_for_teleport();
    update_animation();
    window.draw_image(drawn_pos, image, size, size);
}

//-----------------------------------------------------------------------------------------------------------------------
// Cloud image
TDT4102::Image cloud_image("Images/cloud.png");

// Constructor for Cloud
Cloud::Cloud (int input_direction, double input_speed, std::vector<int> grid_position) : Animated_Ant(input_direction, input_speed, grid_position) {
    start_true_pos_x = grid_position.at(0);
    start_true_pos_y = grid_position.at(1);
    image = cloud_image;
}

// Cloud functions
void Cloud::update(TDT4102::AnimationWindow& window) {
    update_position();
    check_for_teleport();
    window.draw_image(drawn_pos, image, size*2*(speed + 0.8), size*(speed + 0.8)); // Multiplies with speed to get a 3D effect (+ 0.8 to not make the change too drastic)
}

void Cloud::update_animation() {
    // This needs to do nothing in order to not use the ant's version of this function
}


