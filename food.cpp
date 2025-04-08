#include "food.h"
#include <algorithm>


//Picks a random food from the food_array
int Food::random_food(){
    srand(time(0));
    int random_food = rand() % Images.size();
    return random_food;
}

std::vector<int> generate_food_postion(){
    srand(time(0));
    int random_xpos = rand() % 13;
    int random_ypos = rand() % 13;

    return {random_xpos,random_ypos};
}

Food::Food(){
    size = 64;
    true_pos = generate_food_postion();
    food_num = random_food();
    image = Images.at(food_num);
    drawn_pos = {true_pos.at(0)*size, true_pos.at(1)*size};
    //drawn_pos.x += 0; // For some reason, this is necessary for it to work. Just does, idk. JK, doesnt work D:<
    //drawn_pos.y += 0;
}

void Food::update(TDT4102::AnimationWindow& window) {
    drawn_pos = {true_pos.at(0)*size, true_pos.at(1)*size};
    image = Images.at(food_num);
    window.draw_image(drawn_pos, image, size, size);
    //drawn_pos = {64,64};
    //This does not work for some reason. Drawn_pos = {100,100} then moving it -34 in each direction works though ???
    //drawn_pos.x += 1;
    //drawn_pos.x -= 1;
}

void Food::new_position() {
    true_pos = generate_food_postion();
    food_num = random_food();
}

