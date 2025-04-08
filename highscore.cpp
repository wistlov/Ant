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

    window.draw_text(TDT4102::Point{290,200}, "Name", TDT4102::Color::black, 14, TDT4102::Font::times_bold_italic);
    window.draw_text(TDT4102::Point{440,200}, "Score", TDT4102::Color::black, 14, TDT4102::Font::times_bold_italic);
    window.draw_text(TDT4102::Point{540,200}, "Quit-time", TDT4102::Color::black, 14, TDT4102::Font::times_bold_italic);

    //Makes the table
    //Vertical lines
    window.draw_line(TDT4102::Point{220,200}, TDT4102::Point{220,700}, TDT4102::Color:: black);
    window.draw_line(TDT4102::Point{400,200}, TDT4102::Point{400,700}, TDT4102::Color:: black);
    window.draw_line(TDT4102::Point{520,200}, TDT4102::Point{520,700}, TDT4102::Color:: black);
    window.draw_line(TDT4102::Point{610,200}, TDT4102::Point{610,700}, TDT4102::Color:: black);


    //Horizontal lines
    for(int i = 0; i < 17; i ++){
        window.draw_line(TDT4102::Point{220,(i*30)+220}, TDT4102::Point{610,(i*30)+220}, TDT4102::Color:: black);
    }

    

}