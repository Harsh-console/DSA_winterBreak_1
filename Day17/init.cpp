#include<iostream>
#include<SDL2/SDL.h>
#include "init.h"
using namespace std;

bool SDL_Init(SDL_Window*& window, SDL_Renderer*& renderer){
    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        cout<<"SDL Init Error : "<<SDL_GetError()<<endl;
        return false;
    }
    window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    if(!window){
        cout<<"Window error : "<<SDL_GetError()<<endl;
        return false;
    }
    renderer  = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    return true;
}
