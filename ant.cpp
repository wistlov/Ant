#include "ant.h"

// Get functions
int Ants::get_direction(Ants ant) {
    return ant.direction;
}

int Ants::get_speed(Ants ant) {
    return ant.speed;
}

double Ants::get_internal_time(Ants ant) {
    return ant.internal_time;
}

// direction: Left(1), Right(2), Up_Left(3), Up_Right(4), Down_Left(5), Down_Right(6)
// direction_change: left, right, up, down
void Ants::change_direction(Ants ant, std::string direction_change) {
    if (ant.direction == 1) {
        if (direction_change == "up") {
            ant.direction = 3;
        } else if (direction_change == "down") {
            ant.direction = 5;
        }
    } else if (ant.direction == 2) {
        if (direction_change == "up") {
            ant.direction = 4;
        } else if (direction_change == "down") {
            ant.direction = 6;
        }
    } else if (ant.direction == 3 || ant.direction == 4) {
        if (direction_change == "left") {
            ant.direction = 1;
        } else if (direction_change == "right") {
            ant.direction = 2;
        }
    } else if (ant.direction == 5 || ant.direction == 6) {
        if (direction_change == "left") {
            ant.direction = 1;
        } else if (direction_change == "right") {
            ant.direction = 2;
        }
    } 
}


void Ants::update_position(Ants ant) {
    if (ant.direction == 1) { // Left
        ant.drawn_pos.x -= ant.speed;
        ant.distance += ant.speed;

    } else if (ant.direction == 2) { // Right
       
    } else if (ant.direction == 3 || ant.direction == 4) { // Up
        
    } else if (ant.direction == 5 || ant.direction == 6) { // Down
        
    } 
}