#include<SDL2/SDL.h>
#include "settings.h"
#include"utils.h"

void clear(SDL_Renderer*& renderer){
    SDL_SetRenderDrawColor(renderer,BG_COLOR.r, BG_COLOR.g, BG_COLOR.b, BG_COLOR.a);
    SDL_RenderClear(renderer);
}