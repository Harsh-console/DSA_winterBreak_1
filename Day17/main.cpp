/*compile command : 
g++ main.cpp init.cpp quit.cpp utils.cpp -lmingw32 -lSDL2main -lSDL2 -o myapp.exe
*/

#include<SDL2/SDL.h>
#include<iostream>
#include<vector>
#include<random>
#include "init.h"
#include "settings.h"
#include "quit.h"
#include "utils.h"
using namespace std;

int main(int argc, char* argv[]) {
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
    SDL_Init(window, renderer);
    bool running = true;
    SDL_Event event;
    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT)
                running = false;
        }
        clear(renderer);
        SDL_RenderPresent(renderer);
    }
    quit_SDL(window, renderer);
    return 0;
}

