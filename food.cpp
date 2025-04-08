#include "food.h"


//Food images
TDT4102::Image Dragonfruit("Images/Dragonfruit.png");
TDT4102::Image Strawberry("Images/Strawberry.png");
TDT4102::Image Apple("Images/Apple.png");
TDT4102::Image Tomato("Images/Tomato.png");
TDT4102::Image Chees("Images/Chees.png");
TDT4102::Image Cookie("Images/Cookie.png");
TDT4102::Image Sushi("Images/Sushi.png");
TDT4102::Image Watermellon("Images/Watermellon.png");

//Checks if there is food on the board
int food_on_board(int food){
    return food;
}

//Picks a random food from the food_array
void random_food(){
    //food_array[8] = [Dragonfruit, ];
}

int food = 0;

void generate_food(AnimationWindow& window){
    while(food < 10){
    srand(time(0));
    int random_xpos = rand() % 13;
    int random_ypos = rand() % 13;
    window.draw_image(TDT4102::Point{random_xpos*64, random_ypos*64}, Dragonfruit, 64, 64);
    food ++;
    }

}

