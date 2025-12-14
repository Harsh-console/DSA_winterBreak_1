#include<vector>
#include<SDL2/SDL.h>
#include<fstream>
#include<iostream>
#include<string>
using namespace std;

int main(int argv, char* argc[]){
    int mem_number;
    ifstream inFile;
    inFile.open("num_memories.txt");
    inFile >> mem_number;
    inFile.close();
    mem_number++;
    const int WIDTH = 600;
    const int HEIGHT = 600;
    const int GRID_SIZE = 60;
    const int numX = WIDTH / GRID_SIZE, numY = HEIGHT / GRID_SIZE;
    vector<bool> data(numX*numY, false);
    SDL_Window* window = SDL_CreateWindow("Drawing Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
    //SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    int running = 1;
    bool isMouseDown = false;
    SDL_Event event;
    SDL_Rect rect = {-GRID_SIZE, -GRID_SIZE, GRID_SIZE, GRID_SIZE};
    SDL_SetRenderDrawColor(renderer, 255, 165, 50, 255);
    int i, j;
    while(running){
        //Clear Screen
        //SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        //SDL_RenderClear(renderer);

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
                isMouseDown = false;;
            }
            if(event.type == SDL_MOUSEMOTION){
                if(isMouseDown) 
                    if(event.motion.y >= 0 && event.motion.y < HEIGHT && event.motion.x >= 0 && event.motion.x < WIDTH){
                        cout<<"position is : "<<(event.motion.y / GRID_SIZE)*numX + (event.motion.x / GRID_SIZE)<<endl;
                        data[(event.motion.y / GRID_SIZE)*numX + (event.motion.x / GRID_SIZE)] = true;
                    }
            }
            if(event.type == SDL_KEYDOWN){
                if(event.key.keysym.sym == SDLK_ESCAPE){
                    running = false;
                }
            }
        }

        // draw using data
        for(int k = 0; k < numX*numY; k++){
            if(data[k]){
                j = k / numX;
                i = k % numX;
                rect.x = i*GRID_SIZE;
                rect.y = j * GRID_SIZE;
                SDL_RenderFillRect(renderer, &rect);
            }
        }

        if(!running){
            ofstream outFile;
            string fileName = "data" + to_string(mem_number) + ".txt";
            outFile.open(fileName);
            for(int i = 0; i < numX*numY; i++){
                outFile<<(int)data[i]<<" ";
            }
            outFile.close();
            ofstream _outFile;
            _outFile.open("num_memories.txt", ios::trunc);
            _outFile<<mem_number;
            _outFile.close();
        }
        SDL_RenderPresent(renderer);
    }
    
    return 0;
}
