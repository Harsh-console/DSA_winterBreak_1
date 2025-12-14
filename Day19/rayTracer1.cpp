#include<SDL2/SDL.h>
#include<bits/stdc++.h>

struct Pos{
    int x, int y
};

class Player{
    public:
        Pos pos;

    private:

};

using namespace std;
int main(int argv, char* argc[]){
    const int WIDTH = 1200, HEIGHT = 600, GRID_SIZE = 20;
    SDL_Window* window = SDL_CreateWindow("My ray tracer!", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, 0, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    int running = 1;
    SDL_Event event;
    while(running){
        while(SDL_PollEvent(&event)){
            if(event.type == SDL_QUIT){
                running = false;
            }
        }
        // Present the screen
        SDL_RenderPresent(renderer);
    }
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
