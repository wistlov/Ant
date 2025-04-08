#include "food.h"


//Picks a random food from the food_array
int Food::random_food(){
    srand(time(0));
    int random_food = rand() % Images.size();
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

Food::Food(){
    true_pos = generate_food_postion();
    drawn_pos = {128,640};//{true_pos.at(0)*size, true_pos.at(1)*size};
    food_num = random_food();
    drawn_pos.x += 0; // For some reason, this is necessary for it to work. Just does, idk. JK, doesnt work D:<
    drawn_pos.y += 0;
}

void Food::update(TDT4102::AnimationWindow& window) {
    image = Images.at(food_num);
    window.draw_image(drawn_pos, image, size, size);
    //drawn_pos = {64,64};
    //This does not work for some reason. Drawn_pos = {100,100} then moving it -34 in each direction works though ???
    drawn_pos.x += 1;
    drawn_pos.x -= 1;
}



