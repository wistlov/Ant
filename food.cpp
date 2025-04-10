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
    true_pos = generate_food_postion();
    food_num = random_food();
    image = Images.at(food_num);
    drawn_pos = {true_pos.x * size, true_pos.y * size};
}

void Food::update(TDT4102::AnimationWindow& window) {
    drawn_pos = {true_pos.x * size, true_pos.y * size};
    image = Images.at(food_num);
    window.draw_image(drawn_pos, image, size, size);
}

void Food::new_position() {
    true_pos = generate_food_postion();
    food_num = random_food();
}
