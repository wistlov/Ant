#include "highscore.h"


void highscore_menu(int width, int height, AnimationWindow& window, std::vector<std::pair<std::string, int>> scores){
    //Makes the background for the highscore menu
    window.draw_rectangle(TDT4102::Point{0,0}, width, height, TDT4102:: Color::sandy_brown); 
    window.draw_image(TDT4102::Point{0,0}, MC_ramme, 832, 832);

    //Draws the Highscore text at the top
    window.draw_rectangle(TDT4102::Point{200,100}, 432, 632, TDT4102:: Color:: light_grey);
    window.draw_text(TDT4102::Point{220,120}, "HIGHSCORE", TDT4102::Color::yellow, 70, TDT4102::Font::times_bold_italic);
    window.draw_text(TDT4102::Point{217,120}, "HIGHSCORE", TDT4102::Color::black, 70, TDT4102::Font::times_bold_italic);

    window.draw_text(TDT4102::Point{290,200}, "Name", TDT4102::Color::black, 14, TDT4102::Font::times_bold_italic);
    window.draw_text(TDT4102::Point{440,200}, "Score", TDT4102::Color::black, 14, TDT4102::Font::times_bold_italic);
    window.draw_text(TDT4102::Point{540,200}, "Easteregg", TDT4102::Color::black, 14, TDT4102::Font::times_bold_italic);

    // Here are the names and scores printed
    for (int i = 0; i<scores.size(); i++) {
        int y = 230 + i*30;
        //window.draw_text(TDT4102::Point{280,230 + i*30}, scores.at(i), TDT4102::Color::black, 14, TDT4102::Font::times_bold_italic);
        window.draw_text(TDT4102::Point{280, y}, scores[i].first, TDT4102::Color::black, 14, TDT4102::Font::times_bold_italic);  // Navn
        window.draw_text(TDT4102::Point{450, y}, std::to_string(scores[i].second), TDT4102::Color::black, 14, TDT4102::Font::times_bold_italic);  // Poeng
    
    }

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

void difficulty_menu(int width, int height, AnimationWindow& window){
    window.draw_image(TDT4102::Point{0,0}, MC_background, 832, 832);
    window.draw_text(TDT4102::Point{110,360}, "Difficulty", TDT4102::Color::black, 120, TDT4102::Font::courier_bold);
}

void paused_menu(int width, int height, AnimationWindow& window){
    window.draw_text(TDT4102::Point{247,120}, "Paused", TDT4102::Color::black, 120, TDT4102::Font::times_bold_italic);
    
}