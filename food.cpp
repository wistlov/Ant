#include "food.h"


//Checks if there is food on the board
int food_on_board(int food){
    return food;
}

//Picks a random food from the food_array
int random_food(){
    srand(time(0));
    int random_food = rand() % 9;
    return random_food;
}

int food = 0;

std::vector<int> generate_food_postion(){
    srand(time(0));
    int random_xpos = rand() % 13;
    int random_ypos = rand() % 13;
    std::vector<int> vec{random_xpos,random_ypos};

    return vec;
}

std::vector<int> vec{0,0};

Food::Food(){
    Images = {Dragonfruit ,Strawberry, Apple, Tomato, Chees, Cookie, Sushi, Watermellon};
    image = Images.at(random_food());
    true_pos = vec; //generate_food_postion();
    drawn_pos = {true_pos.at(0)*size, true_pos.at(1)*size};
}

void Food::update(TDT4102::AnimationWindow& window) {
    window.draw_image(drawn_pos, image, size, size);
}

TDT4102::Image Dragonfruit("Images/Dragonfruit.png");
TDT4102::Image Strawberry("Images/Strawberry.png");
TDT4102::Image Apple("Images/Apple.png");
TDT4102::Image Tomato("Images/Tomato.png");
TDT4102::Image Chees("Images/Chees.png");
TDT4102::Image Cookie("Images/Cookie.png");
TDT4102::Image Sushi("Images/Sushi.png");
TDT4102::Image Watermellon("Images/Watermellon.png");