#include<SDL2/SDL.h>
#include "quit.h"

void quit_SDL(SDL_Window*& window, SDL_Renderer*& renderer){
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}