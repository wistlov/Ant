#include "grid.h"



// Grid 13X13
void Grid(int grid_width, int grid_height, int WIDTH, int HEIGHT, AnimationWindow& window) 
{ //grid_width and grid_height is the number of squares. WIDTH and HEIGHT is the window sizes
    
   //Draw checkboard background
   int square_size = 64; //Size of squres on board
   for (int i = 0; i < WIDTH; i+=square_size) {
    for (int j = 0; j < HEIGHT; j+=square_size) {


        Point cor1(i,j);
        Point cor2(i+square_size,j);
        Point cor3(i+square_size,j+square_size);
        Point cor4(i,j+square_size);
        if((i/square_size)%2 == (j/square_size)%2) {
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