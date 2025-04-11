#include "food.h"
#include <algorithm>

// Picks a random food from the food_array
int Food::random_food() {
    srand(time(0));
    int random_food = rand() % Images.size();
    return random_food;
}

GridPos generate_food_postion() {
    srand(time(0));
    int random_xpos = rand() % 13;
    int random_ypos = rand() % 13;
    return GridPos{random_xpos, random_ypos};
}

Food::Food() {
    size = 64;
    food_puls = 1.0; //makes the food puls
    food_control = 0; // makes sure thatbthe food don't disapare
    true_pos = generate_food_postion();
    food_num = random_food();
    image = Images.at(food_num);
    drawn_pos = {true_pos.x * size, true_pos.y * size};
    food_type = food_num + 1;
}

void Food::update(TDT4102::AnimationWindow& window) {
    drawn_pos = {true_pos.x * size, true_pos.y * size};
    image = Images.at(food_num);
    window.draw_image(drawn_pos, image, size*food_puls, size*food_puls);

    //Makes the food anmation, the pulsing
    if(food_control <= 100 ) {
        food_puls -= 0.0025;
        food_control += 1;
    }
    else if (food_control <= 200) {
        food_puls += 0.0025;
        food_control += 1;
    }
    else {
        food_control = 0;
    }


}

void Food::new_position() {
    true_pos = generate_food_postion();
    food_num = random_food();
}
