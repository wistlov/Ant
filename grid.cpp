#include "grid.h"



// Grid 15X15
void Grid(int grid_width, int grid_height, int WIDTH, int HEIGHT, AnimationWindow& window) 
{ //width and height is the number of squares. WIDTH and HEIGHT is the window sizes
   //Draw checkboard background
   for (int i = 0; i < WIDTH; i+=50) {
    for (int j = 0; j < HEIGHT; j+=50) {


        Point cor1(i,j);
        Point cor2(i+50,j);
        Point cor3(i+50,j+50);
        Point cor4(i,j+50);
        if((i/50)%2 == (j/50)%2) {
            window.draw_quad(cor1, cor2, cor3, cor4, Color::lawn_green);
        } else {
            window.draw_quad(cor1, cor2, cor3, cor4, Color::lime_green);
        }
    }
}
    // Draw horizontal lines
    for (int j = 0; j <= grid_height; j++) {
        Point start(0, j * (HEIGHT / grid_height));
        Point end(WIDTH, j * (HEIGHT / grid_height));
        window.draw_line(start, end, Color::black);
    }


        // Draw vertical lines
    for (int i = 0; i <= grid_width; i++) {
        Point start(i * (WIDTH / grid_width), 0);
        Point end(i * (WIDTH / grid_width), HEIGHT);
        window.draw_line(start, end, Color::black);


    }

}