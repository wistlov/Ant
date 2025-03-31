#include "highscore.h"


void highscore_menu(int width, int height, AnimationWindow& window){
    //Makes the background for the highscore menu
    window.draw_rectangle(TDT4102::Point{0,0}, width, height, TDT4102:: Color::sandy_brown); 
    window.draw_rectangle(TDT4102::Point{0,200}, width, 60, Color::saddle_brown);
    window.draw_rectangle(TDT4102::Point{0,400}, width, 60, Color::saddle_brown);
    window.draw_rectangle(TDT4102::Point{0,600}, width, 60, Color::saddle_brown);

    //Draws the Highscore text at the top
    window.draw_rectangle(TDT4102::Point{200,100}, 432, 632, TDT4102:: Color:: light_grey);
    window.draw_text(TDT4102::Point{220,120}, "HIGHSCORE", TDT4102::Color::yellow, 70, TDT4102::Font::times_bold_italic);
    window.draw_text(TDT4102::Point{217,120}, "HIGHSCORE", TDT4102::Color::black, 70, TDT4102::Font::times_bold_italic);

    //Makes the table
    window.draw_line(TDT4102::Point{220,140}, TDT4102::Point{220,140}, TDT4102::Color:: black);

    window.draw_line(TDT4102::Point{220,140}, TDT4102::Point{220,340}, TDT4102::Color:: black);

}