#include "resources.h"

// Global variables
std::string game_screen = "menu";// sets which state the game is in
bool ants_moving = false; // While this is true, the player and follower ants should move. Otherwise, they should not.
extern std::string button_input = "none"; // This is here to share button inputs the GUI picks up to the player ant.
extern double player_ant_speed = 1.0; // Speed of the player ant, duh

// Ant images
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

// Cloud image
TDT4102::Image cloud_image("Images/cloud.png");

// Food images

TDT4102::Image Hamburger("Images/Hamburger.png");
TDT4102::Image Bowl("Images/bowl.png");
TDT4102::Image Spagheti("Images/Spagheti.png");