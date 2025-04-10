#include "ant.h"

std::vector<Follower_Ant> follower_ant_list; // This houses the follower ants

//--------------------------------------------------------------------------------//
// Constructor for Ants
Ants::Ants(int input_direction, double input_speed, GridPos grid_position) {
    int frame_step = 0;
    size = 64;
    direction = input_direction;
    speed = input_speed;
    true_pos = grid_position;
    distance = 0.0;
    animation_frame = 0;

    if (direction == 1) image = Left1;
    else if (direction == 2) image = Right1;
    else if (direction == 3) image = Up1_Left;
    else if (direction == 4) image = Up1_Right;
    else if (direction == 5) image = Down1_Left;
    else if (direction == 6) image = Down1_Right;
}

int Ants::get_direction() { return direction; }
int Ants::get_speed() { return speed; }
double Ants::get_internal_time() { return internal_time; }

void Ants::change_direction(std::string direction_change) {
    if (direction == 1) {
        if (direction_change == "up") direction = 3;
        else if (direction_change == "down") direction = 5;
    } else if (direction == 2) {
        if (direction_change == "up") direction = 4;
        else if (direction_change == "down") direction = 6;
    } else if (direction == 3 || direction == 4) {
        if (direction_change == "left") direction = 1;
        else if (direction_change == "right") direction = 2;
    } else if (direction == 5 || direction == 6) {
        if (direction_change == "left") direction = 1;
        else if (direction_change == "right") direction = 2;
    }
}

void Ants::update_position() {
    if (direction == 1) {
        drawn_pos.x -= speed;
        distance += speed;
        drawn_pos.x = true_pos.x * size - distance;
        drawn_pos.y = true_pos.y * size;
        if (distance >= size) {
            true_pos.x -= 1;
            distance = 0;
            drawn_pos.x = true_pos.x * size;
            change_direction(saved_direction);
        }
    } else if (direction == 2) {
        drawn_pos.x += speed;
        distance += speed;
        drawn_pos.x = true_pos.x * size + distance;
        drawn_pos.y = true_pos.y * size;
        if (distance >= size) {
            true_pos.x += 1;
            distance = 0;
            drawn_pos.x = true_pos.x * size;
            change_direction(saved_direction);
        }
    } else if (direction == 3 || direction == 4) {
        drawn_pos.y -= speed;
        distance += speed;
        drawn_pos.y = true_pos.y * size;
        if (distance >= size) {
            true_pos.y -= 1;
            distance = 0;
            drawn_pos.y = true_pos.y * size;
            change_direction(saved_direction);
        }
    } else if (direction == 5 || direction == 6) {
        drawn_pos.y += speed;
        distance += speed;
        drawn_pos.y = true_pos.y * size;
        if (distance >= size) {
            true_pos.y += 1;
            distance = 0;
            drawn_pos.y = true_pos.y * size;
            change_direction(saved_direction);
        }
    }
}

void Ants::update_animation() {
    internal_time += 1 * speed;
    if (internal_time >= 12) {
        internal_time = 0;
        animation_frame = 1 - animation_frame;
        switch (direction) {
            case 1: image = (animation_frame == 0 ? Left1 : Left2); 
                break;
            case 2: image = (animation_frame == 0 ? Right1 : Right2); 
                break;
            case 3: image = (animation_frame == 0 ? Up1_Left : Up2_Left); 
                break;
            case 4: image = (animation_frame == 0 ? Up1_Right : Up2_Right); 
                break;
            case 5: image = (animation_frame == 0 ? Down1_Left : Down2_Left); 
                break;
            case 6: image = (animation_frame == 0 ? Down1_Right : Down2_Right); 
                break;
        }
    }
}

void Ants::update(TDT4102::AnimationWindow& window) {
    update_position();
    update_animation();
    window.draw_image(drawn_pos, image, size, size);
}

Animated_Ant::Animated_Ant(int input_direction, double input_speed, GridPos grid_position)
    : Ants(input_direction, input_speed, grid_position) {
    start_true_pos = grid_position.x;
}

void Animated_Ant::check_for_teleport() {
    if (direction == 1 && true_pos.x < -1) true_pos.x = 14;
    else if (direction != 1 && true_pos.x > 14) true_pos.x = -1;
}

void Animated_Ant::update(TDT4102::AnimationWindow& window) {
    update_position();
    check_for_teleport();
    update_animation();
    window.draw_image(drawn_pos, image, size, size);
}

Player_Ant::Player_Ant(int input_direction, double input_speed, GridPos grid_position)
    : Ants(input_direction, input_speed, grid_position) {}

void Player_Ant::check_input() {
    if (saved_direction != button_input) saved_direction = button_input;
}

void Player_Ant::update_position() {
    if (direction == 1) {
        distance += speed;
        drawn_pos.x = true_pos.x * size - distance;
        drawn_pos.y = true_pos.y * size;
    } else if (direction == 2) {
        distance += speed;
        drawn_pos.x = true_pos.x * size + distance;
        drawn_pos.y = true_pos.y * size;
    } else if (direction == 3 || direction == 4) {
        distance += speed;
        drawn_pos.x = true_pos.x * size;
        drawn_pos.y = true_pos.y * size - distance;
    } else if (direction == 5 || direction == 6) {
        distance += speed;
        drawn_pos.x = true_pos.x * size;
        drawn_pos.y = true_pos.y * size + distance;
    }
    if (distance >= size) {
        true_pos.x += (drawn_pos.x - true_pos.x * size) / size;
        true_pos.y += (drawn_pos.y - true_pos.y * size) / size;
        distance = 0;
        change_direction(saved_direction);
    }
}

bool Player_Ant::check_wall_collision() {
    if (true_pos.x < 0 || true_pos.x > 12 || true_pos.y < 0 || true_pos.y > 12) {
        return true;
    } else {
        return false;
    }
}

bool Player_Ant::check_for_food(GridPos food_pos) {
    return (true_pos.x == food_pos.x && true_pos.y == food_pos.y);
}

void Player_Ant::update(TDT4102::AnimationWindow& window) {
    check_input();
    update_position();
    update_animation();
    window.draw_image(drawn_pos, image, size, size);
}

Follower_Ant::Follower_Ant(int input_direction, double input_speed, GridPos grid_position, int input_id)
    : Player_Ant(input_direction, input_speed, grid_position) {
    ant_id = input_id;
    drawn_pos.x = true_pos.x * size;
    drawn_pos.y = true_pos.y * size;
}

void Follower_Ant::set_destination(const GridPos& pos) {
    move = true;
    if (pos.x > true_pos.x) change_direction("right");
    else if (pos.x < true_pos.x) change_direction("left");
    else if (pos.y > true_pos.y) change_direction("down");
    else if (pos.y < true_pos.y) change_direction("up");
    else move = false;
}

void Follower_Ant::update(TDT4102::AnimationWindow& window) {
    update_position();
    update_animation();
    window.draw_image(drawn_pos, image, size, size);
}

void Follower_Ant::update_position() {
    if (move) {
        if (direction == 1) {
            distance += speed;
            drawn_pos.x = true_pos.x * size - distance;
            drawn_pos.y = true_pos.y * size;
        } else if (direction == 2) {
            distance += speed;
            drawn_pos.x = true_pos.x * size + distance;
            drawn_pos.y = true_pos.y * size;
        } else if (direction == 3 || direction == 4) {
            distance += speed;
            drawn_pos.x = true_pos.x * size;
            drawn_pos.y = true_pos.y * size - distance;
        } else if (direction == 5 || direction == 6) {
            distance += speed;
            drawn_pos.x = true_pos.x * size;
            drawn_pos.y = true_pos.y * size + distance;
        }
        if (distance >= size) {
            true_pos.x += (drawn_pos.x - true_pos.x * size) / size;
            true_pos.y += (drawn_pos.y - true_pos.y * size) / size;
            distance = 0;
        }
    }
}

Cloud::Cloud(int input_direction, double input_speed, GridPos grid_position)
    : Animated_Ant(input_direction, input_speed, grid_position) {
    start_true_pos_x = grid_position.x;
    start_true_pos_y = grid_position.y;
    image = cloud_image;
}

void Cloud::update(TDT4102::AnimationWindow& window) {
    update_position();
    check_for_teleport();
    window.draw_image(drawn_pos, image, size * 2 * (speed + 0.8), size * (speed + 0.8));
}

void Cloud::update_animation() {
    // This needs to do nothing in order to not use the ant's version of this function
}
