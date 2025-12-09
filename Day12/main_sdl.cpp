#include <SDL2/SDL.h>
#include<bits/stdc++.h>
#include <random>
using namespace std;

template<typename T, typename... Args>
vector<T> make_vector(Args&&... args){
    return vector<T>{forward<Args>(args)...};
}

int main(int argc, char* argv[]) {
    int WIDTH = 1200, HEIGHT = 600;
    int TILE = 20;
    int x_vel = 150;
    int y_vel = 150;
    int score = 0;
    float min_dist = 4;
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL could not initialize! SDL_Error: "
                  << SDL_GetError() << std::endl;
        return 1;
    }

    // Create Window
    SDL_Window* window = SDL_CreateWindow(
        "SDL Window",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        WIDTH, HEIGHT,
        SDL_WINDOW_SHOWN
    );

    if (!window) {
        std::cerr << "Window could not be created! SDL_Error: "
                  << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    // Create Renderer
    SDL_Renderer* renderer = SDL_CreateRenderer(
        window, -1, SDL_RENDERER_ACCELERATED
    );

    if (!renderer) {
        std::cerr << "Renderer could not be created! SDL_Error: "
                  << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    bool running = true;
    bool collision = false;
    bool is_food = false;
    SDL_Event event;

    Uint32 lastTime = SDL_GetTicks();
    Uint32 last_deltaTime = SDL_GetTicks();
    int frames = 0;
    
    // Generate Random Numbers
    random_device rd;
    mt19937 gen(rd()); // Mersenne Twistter generator
    uniform_int_distribution<> dist_x(0, WIDTH - TILE);
    uniform_int_distribution<> dist_y(0, HEIGHT - TILE);

    // Snake Game
    vector<vector<float>> snake; // snake[0]=head, snake[1] = 1st block of snake after head
    snake.push_back(make_vector<float>(dist_x(gen), dist_y(gen)));
    float food[2];
    int head_dir = 0; // 0 = stop, 1 = up, 2 = right, 3 = down, 4 = left
    vector<int> dir;
    dir.push_back(head_dir);

    // Main Loop
    while (running) {
        float prev_x = snake[0][0];
        float prev_y = snake[0][1];
        switch(head_dir){
            case 1:
                prev_y += TILE;
                break;
            case 2:
                pre_x -= TILE;
                break;
            case 3:
                prev_y -= TILE;
                break;
            case 4:
                prev_x += TILE;
                break;
        }
        // find delta_time
        Uint32 current_deltaTime = SDL_GetTicks();
        float delta_time = (current_deltaTime - last_deltaTime) / 1000.0f;
        last_deltaTime = current_deltaTime;
        
        // update movement using delta time
        float move_x = x_vel * delta_time;
        float move_y = y_vel * delta_time;

        // Clear screen (black)
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        SDL_Delay(1);
        // count number of frames in the second
        frames++;

        Uint32 currentTime = SDL_GetTicks();
        if(currentTime - lastTime >= 1000){ // 1 second passed
            float fps = frames * 1000.0f / (currentTime - lastTime);
            std::string title = "FPS : " + std::to_string((int)fps);
            SDL_SetWindowTitle(window, title.c_str());

            frames = 0;
            lastTime = currentTime;

            
        }
        // Event polling
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
            if(event.type == SDL_KEYDOWN){
                if(event.key.keysym.sym == SDLK_ESCAPE) running = false;
                if(event.key.keysym.sym == SDLK_UP) head_dir = 1;
                if(event.key.keysym.sym == SDLK_RIGHT) head_dir = 2;
                if(event.key.keysym.sym == SDLK_DOWN) head_dir = 3;
                if(event.key.keysym.sym == SDLK_LEFT) head_dir = 4;
                if(event.key.keysym.sym == SDLK_SPACE) head_dir = 0;
            }
        }
        dir[0] = head_dir;
        // check collision with boundary
        if(snake[0][0] == 0 && head_dir == 4) collision = true;
        if(snake[0][0] == WIDTH - TILE && head_dir == 2) collision = true;
        if(snake[0][1] == 0 && head_dir == 1) collision = true;
        if(snake[0][1] == HEIGHT - TILE && head_dir == 3) collision = true;

        // make food
        if(!is_food){
            food[0] = dist_x(gen);
            food[1] = dist_y(gen);
            score++;
            cout<<"Score : "<<score<<endl;
            is_food = true;
        }

        //move snake
        switch(head_dir){
            case 1: 
                snake[0][1] -= move_y;
                break;
            case 2:
                snake[0][0] += move_x;
                break;
            case 3:
                snake[0][1] += move_y;
                break;
            case 4:
                snake[0][0] -= move_x;
                break;
        }
        for(int i = 1; i < snake.size(); i++){
            float temp_x = snake[i][0];
            float temp_y = snake[i][1];
            snake[i][0] = prev_x;
            snake[i][1] = prev_y;
            prev_x = temp_x;
            prev_y = temp_y;
            dir[i] = dir[i - 1];
            switch(dir[i]){
                case 1: 
                    prev_y += TILE;
                    break;
                case 2:
                    prev_x -= TILE;
                    break;
                case 3:
                    prev_y -= TILE;
                    break;
                case 4:
                    prev_x += TILE;
                    break;
            }
        }

        // Draw Food
        SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
        SDL_Rect rect = {food[0], food[1], TILE, TILE};
        SDL_RenderFillRect(renderer, &rect);

        // Draw Snake
        for(auto &block : snake){
            SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
            SDL_Rect rect = {block[0], block[1], TILE, TILE};
            SDL_RenderFillRect(renderer, &rect);
        }

        //check if food could be eaten
        if(abs(snake[0][0] - food[0]) + abs(snake[0][1] - food[1]) <= min_dist){
            is_food = false;
            vector<float> new_block = snake.back();
            dir.push_back(dir.back());
            switch(dir.back()){
                case 1:
                    new_block[1] += TILE;
                    break;
                case 2:
                    new_block[0] -= TILE;
                    break;
                case 3:
                    new_block[1] -= TILE;
                    break;
                case 4:
                    new_block[0] += TILE;
                    break;
            }
            snake.push_back(new_block);
            prev_x = new_block[0];
            prev_y = new_block[1];
        }

        /*
        // Draw a red rectangle
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_Rect rect = { 200, 150, 300, 200 }; // x, y, w, h
        SDL_RenderFillRect(renderer, &rect);
        */

        // Present to screen
        SDL_RenderPresent(renderer);
    }

    // Cleanup
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}

