//includes
#include<SDL2/SDL.h>
#include<vector>
#include<iostream>
using namespace std;
//----------------

int main(int argc, char* argv[]){
    //window setup
    const int WIDTH = 1200, HEIGHT = 600, GRID_SIZE = 5;
    SDL_Window* window = SDL_CreateWindow("ray tracer", WIDTH, HEIGHT, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SDL_WINDOW_SHOWN);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, 0, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED);
    int running = 1;
    SDL_Event event;
    //-------------------------
    
    //main loop
    while(running){
        //clear the screen
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        //-----------------

        //handle SDL Poll Events
        while(SDL_PollEvent(&event)){
            if(event.type == SDL_QUIT){
                running = false;
            }
        }
        //--------------------

        //Update the screen
        SDL_RenderPresent(renderer);
        //-------------------

    }
    //-----------------------------

    //Quit SDL
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    //-------------

    return 0;
}
