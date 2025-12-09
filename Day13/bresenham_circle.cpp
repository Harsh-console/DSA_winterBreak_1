#include <SDL2/SDL.h>
#include <bits/stdc++.h>
using namespace std;

void add_mirror_points(vector<pair<float, float>> &points, float &x, float &y){
    points.push_back({x, y});
    points.push_back({x, -y});
    points.push_back({-x, y});
    points.push_back({-x, -y});
    points.push_back({y, x});
    points.push_back({y, -x});
    points.push_back({-y, x});
    points.push_back({-y, -x});

}

void gen_points(vector<pair<float, float>> &points, float r){
    // start at (0, r) then for increasing x at each iteration we decide wheather to decrease y or not to decrease y
    float x = 0, y = r;
    add_mirror_points(points, x, y);
    float d = 3 - 2 *r;
    while(y > x){
        if(d < 0) d += 4*x++ + 6;
        else d += 4*(x++ - y--) + 10;
        add_mirror_points(points, x, y);
    }
}

int main(int argc, char* argv[]) {
    
    int WIDTH = 1200, HEIGHT = 600;

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
        WIDTH,                    // Width
        HEIGHT,                    // Height
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

    // find points on circle
    vector<pair<float, float>> points;
    float r;
    int w = 1;
    int h = 1;
    cin>>r;
    gen_points(points, r);
    while (running) {

        // 4a. Handle Events
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
        }

        // 4b. Clear screen
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // black
        SDL_RenderClear(renderer);

        // 4c. Draw things here
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        for(int i = 0; i < points.size(); i++){
            //SDL_RenderDrawPoint(renderer, (int)point.first + WIDTH / 2,(int) point.second + HEIGHT / 2);

            SDL_Rect rect = {(int)points[i].first + WIDTH / 2, (int)points[i].second + HEIGHT / 2, w, h};
            SDL_RenderFillRect(renderer, &rect);
        }
        // 4d. Show everything
        SDL_RenderPresent(renderer);
    }

    // 5. Cleanup
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}

