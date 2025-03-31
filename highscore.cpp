#include "highscore.h"


void highscore_menu(int width, int height, AnimationWindow& window){
    window.draw_rectangle(TDT4102::Point{0,0}, width, height, TDT4102:: Color::sandy_brown); 
    window.draw_rectangle(TDT4102::Point{0,200}, width, 60, Color::saddle_brown);
    window.draw_rectangle(TDT4102::Point{0,400}, width, 60, Color::saddle_brown);
    window.draw_rectangle(TDT4102::Point{0,600}, width, 60, Color::saddle_brown);

    window.draw_rectangle(TDT4102::Point{200,100}, 432, 632, TDT4102:: Color:: light_grey);

}