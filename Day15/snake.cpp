#include <SDL2/SDL.h>
#include <iostream>
#include<bits/stdc++.h>
#include <random>
using namespace std;

// snake is array of snake blocks, so each block is separate entity except the head. its like stack but we only add.
// we can make a class block with characteristics pos . and prev position should be global one . or we don't even need another class for that. even vector<vector<int>> should be sufficient. and 

int main(int argc, char* argv[]) {
    // constants
    int WIDTH = 1200, HEIGHT = 600;
    int TILE = 20;
    int numX = WIDTH / TILE;
    int numY = HEIGHT / TILE;
    int min_dist = 5;

    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cout << "SDL Init Error: " << SDL_GetError() << std::endl;
        return 1;
    }
    SDL_Window* window = SDL_CreateWindow(
        "SDL2 Window",          // Title
        SDL_WINDOWPOS_CENTERED, // X position
        SDL_WINDOWPOS_CENTERED, // Y position
        WIDTH,                    // Width
        HEIGHT,                    // Height
        SDL_WINDOW_SHOWN
    );
    if (!window) {
        std::cout << "Window Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }
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

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> ind_x(0, numX - 1);
    uniform_int_distribution<> ind_y(0, numY - 1);

    // snake and food
    vector<vector<int>> snake;
    snake.push_back(vector<int>{ind_x(gen), ind_y(gen)});
    int head_dir = 0; // 0 : stop, 1 : up, 2: right, 3 : down, 4: left
    int food[2];
    bool is_food = false;
    int score = 0;
    // 4. Main Loop
    bool running = true;
    SDL_Event event;
    SDL_Rect rect = {0, 0, TILE, TILE};
    int tempX = 0, tempY = 0;
    int prev_X, prev_Y;
    while (running) {
        SDL_Delay(30);
        // If there is no food make the food
        prev_X = snake[0][0];
        prev_Y = snake[0][1];
        if(!is_food){
            food[0] = ind_x(gen);
            food[1] = ind_y(gen);
            is_food = true;
        }
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // black
        SDL_RenderClear(renderer);
        /*
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_Rect rect = { 200, 150, 300, 200 };
        SDL_RenderFillRect(renderer, &rect);
        */

        // move Snake head
        switch(head_dir){
            case 1:
                snake[0][1] -= 1;
                break;
            case 2:
                snake[0][0] += 1;
                break;
            case 3:
                snake[0][1] += 1;
                break;
            case 4:
                snake[0][0] -= 1;
                break;
        }
        //border teleportation
        if(snake[0][0] < 0) snake[0][0] += numX;
        if(snake[0][0] >= numX) snake[0][0] -= numX;
        if(snake[0][1] < 0) snake[0][1] += numY;
        if(snake[0][1] >= numY) snake[0][1] -= numY;
        // draw snake body
        for(int i = 1; i < snake.size(); i++){
            tempX = snake[i][0];
            tempY = snake[i][1];
            snake[i][0] = prev_X;
            snake[i][1] = prev_Y;
            prev_X = tempX;
            prev_Y = tempY;
        }

        //eat food
        if(abs(food[0] - snake[0][0]) + abs(food[1] - snake[0][1]) < min_dist){
            is_food = false;
            score++;
            cout<<"score : "<<score<<endl;
            vector<int> newBlock {prev_X, prev_Y};
            snake.push_back(newBlock);
        }
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
            if(event.type == SDL_KEYDOWN){
                if(event.key.keysym.sym == SDLK_UP) head_dir = 1;
                if(event.key.keysym.sym == SDLK_RIGHT) head_dir = 2;
                if(event.key.keysym.sym == SDLK_DOWN) head_dir = 3;
                if(event.key.keysym.sym == SDLK_LEFT) head_dir = 4;
            }
        }
        // draw Snake
        SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
        for(int i = 0; i < snake.size(); i++){
            rect.x = snake[i][0] * TILE;
            rect.y = snake[i][1] * TILE;
            SDL_RenderFillRect(renderer, &rect);
        }
        // draw food
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        rect.x = food[0] * TILE;
        rect.y = food[1] * TILE;
        SDL_RenderFillRect(renderer, &rect);
        SDL_SetRenderDrawColor(renderer, 122, 0, 0, 255);
        rect.w = 2 * TILE;
        rect.h = 2 * TILE;
        SDL_RenderFillRect(renderer, &rect);
        rect.w = TILE;
        rect.h = TILE;

        //Present the screen
        SDL_RenderPresent(renderer);

    }
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}


