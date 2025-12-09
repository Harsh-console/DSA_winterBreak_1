#include <SDL2/SDL.h>
#include <iostream>
#include<vector>
#include<random>
using namespace std;

int main(int argc, char* argv[]) {
    //constants
    int WIDTH = 1200;
    int HEIGHT = 600;
    int TILE = 30;
    int delay_time = 10;
    SDL_Delay(delay_time);

    // 1. Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cout << "SDL Init Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    // 2. Create Window
    SDL_Window* window = SDL_CreateWindow(
        "SDL2 Window",          // Title
        SDL_WINDOWPOS_CENTERED, // X position
        SDL_WINDOWPOS_CENTERED, // Y position
        800,                    // Width
        600,                    // Height
        SDL_WINDOW_SHOWN
    );

    if (!window) {
        std::cout << "Window Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    // 3. Create Renderer
    SDL_Renderer* renderer = SDL_CreateRenderer(
        window, -1,
        SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
    );

    if (!renderer) {
        std::cout << "Renderer Error: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    // 4. Main Loop
    bool running = true;
    SDL_Event event;

    // random numbers 
    random_device rd;
    mt19937 gen(rd()); // mersenne twistter generator
    uniform_int_distribution<> dist_x(0, WIDTH - TILE);
    uniform_int_distribution<> dist_y(0, HEIGHT - TILE);

    // snake
    vector<vector<int>> snake;
    vector<int> food;
    bool is_food = false;
    int prev_x, prev_y;
    int head_dir  =
    while (running) {

        // 4a. Handle Events
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
            if( event.type == SDL_KEYDOWN){
                if(event.key.keysym.sym == SDL_UP){
                    
                }
            }
        }

        // 4b. Clear screen
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // black
        SDL_RenderClear(renderer);
        /*
        // 4c. Draw things here
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_Rect rect = { 200, 150, 300, 200 };
        SDL_RenderFillRect(renderer, &rect);
        */
        // Draw Grid
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); //white grid lines
        for(int i = 0; i < WIDTH / TILE; i++){
            SDL_RenderDrawLine(renderer, i * TILE, 0, i * TILE, HEIGHT);
        }
        for(int j = 0; j < HEIGHT / TILE; j++){
            SDL_RenderDrawLine(renderer, 0, j * TILE, WIDTH, j * TILE);
        }
        // Draw Snake
        SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
        for(int i = 0; i < snake.size; i++){
            SDL_Rect rect = {snake[i][0], snake[i][1], TILE, TILE};
        }
        SDL_SetRenderDrawColor(renderer, 0, 255, 255);
        // 4d. Show everything
        SDL_RenderPresent(renderer);
    }

    // 5. Cleanup
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}

