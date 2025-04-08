#pragma once

#include "std_lib_facilities.h"
#include "AnimationWindow.h"
#include "widgets/Button.h"
#include "game.h"
#include "ant.h"
#include <iostream>



// Buttons
Button make_play_button(int posx, int posy, int width, int height, AnimationWindow& window);
Button make_highscore_button(int posx, int posy, int width, int height, AnimationWindow& window);
Button make_quit_button(int posx, int posy, int width, int height, AnimationWindow& window);


// Menu "Base"/Background
void menu_overall_background(int width, int height, AnimationWindow& window);

//Escape to main menu
void Esacpe_menu(AnimationWindow& window);
// Callbacks
// (These are functions that buttons can make happen when clicked)
void play(); 
void highscore(); 
void quit();

// The class for the graphics window
class Ant_Window : public TDT4102::AnimationWindow {
    private:
        // Constants for the board and window
        static constexpr int square_size = 64;
        static constexpr int board_width = 13; // Number of squares
        static constexpr int board_height = 13; // Number of squares
        static constexpr int WIDTH = 832; // Width of the window 
        static constexpr int HEIGHT = 832; // Height of the Window
        static constexpr int window_start_x = 400;
        static constexpr int window_start_y = 25;
        static constexpr std::string window_name = "Ant";
        static constexpr int button_width = 0;
        static constexpr int button_height = 0;

        // Makes the ANT text
        TDT4102::Point location {295, 0}; //Start point of the text
        std::string message = "ANT"; // what the text is
        Color textColor = TDT4102::Color::dark_red;
        static constexpr int fontSize = 120; 
        TDT4102::Font fontFace = TDT4102::Font::times_bold;

        // Other variables++
        std::vector<std::vector<TDT4102::Point>> tiles{};

        // Functions
        void make_grid(); // Self explanatory 
        void draw_grid(); // Should have all constants in the class itself, therefore not in need of inputs
        
    public:
        // Constructor
        Ant_Window();
};
