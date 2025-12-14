#include<SDL2/SDL.h>
#include<bits/stdc++.h>
using namespace std;

int main(int argv, char* argc[]){
    SDL_Init(SDL_INIT_VIDEO);
    const int WIDTH = 1200, HEIGHT = 600;

    SDL_Window* window = SDL_CreateWindow("Drawing Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    int running = 1;
    SDL_Event event;
    
    bool pixel[HEIGHT][WIDTH] = {false};

    SDL_Rect rect = {-1, -1, 5, 5};
    SDL_SetRenderDrawColor(renderer, 255, 165, 0, 255);
    bool isMouseDown = false;

    Uint32 lastTime = SDL_GetTicks();
    int frames = 0;
    int fps = 0;

    while(running){
        SDL_Delay(10);
        while(SDL_PollEvent(&event)){
            if(event.type == SDL_QUIT){
                running = 0;
            }
            if(event.type == SDL_MOUSEBUTTONDOWN){
                //SDL_Log("Button Down. Current mouse position is: (%d, %d)", event.motion.x, event.motion.y);
                //pixel[event.motion.y][event.motion.x] = true;
                isMouseDown = true;

            }
            if(event.type == SDL_MOUSEBUTTONUP){
                //SDL_Log("Button Up. Current mouse position is: (%d, %d)", event.motion.x, event.motion.y);
                isMouseDown = false;
            }
            if(event.type == SDL_MOUSEMOTION){
                if(isMouseDown) pixel[event.motion.y][event.motion.x] = true;
            }
            for(int y = 0; y < HEIGHT; ++y){
                for(int x = 0; x < WIDTH; ++x){
                    if(pixel[y][x]){
                        rect.x = x; rect.y = y;
                        SDL_RenderFillRect(renderer, &rect);
                    }
                }
            }
            SDL_RenderPresent(renderer);
        }
        // FPS logic
        frames++;
        Uint32 currentTime = SDL_GetTicks();

        if (currentTime - lastTime >= 1000) {
            fps = frames;
            frames = 0;
            lastTime = currentTime;

            std::string title = "FPS: " + std::to_string(fps);
            SDL_SetWindowTitle(window, title.c_str());
        }
    }
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
