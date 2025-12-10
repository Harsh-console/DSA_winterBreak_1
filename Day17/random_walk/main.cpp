#include<SDL2/SDL.h>
#include<stdio.h>
#include<stdlib.h>
#include<random>
#include<time.h>

#define SCALE 4
#define AGENT_SIZE 2

const int WIDTH = 1200;
const int HEIGHT = 600;

typedef struct{
    int vx;
    int vy;
}Velocity;

typedef struct{
    int x; int y;
    Uint32 color;
}Agent;

Velocity get_rand_v(){
    int choice = rand() % 4;
    switch(choice){
        case 0:
            return (Velocity) {0, -1};
            break;
        case 1:
            return (Velocity) {1, 0};
            break;
        case 2:
            return (Velocity) {0, 1};
            break;
        case 3:
            return (Velocity) {-1, 0};
            break;
    }
    exit(-1);
}

void move_agent(SDL_Surface* psurface, Agent* pagent, const Uint32 BG_COLOR){
    SDL_Rect rect = (SDL_Rect){pagent->x, pagent->y, AGENT_SIZE, AGENT_SIZE};
    Velocity v = get_rand_v();
    for(int i = 0; i < SCALE; i++){
        pagent->x += SCALE * v.vx;
        pagent->y += SCALE * v.vy;
        SDL_FillRect(psurface, &rect, BG_COLOR);
    }  
}

int main(int argc, char* argv[]){
    int num_agents;
    if(argc == 1){
        num_agents = 5;
    }
    else if(argc == 2){
        num_agents = atoi(argv[1]);
    }
    else{
        printf("Usage : %s<num-of-agents>\n", argv[0]);
        return -1;
    }

    srand(time(NULL));

    SDL_Window* pwindow = SDL_CreateWindow("Random Walk", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, 0);
    SDL_Surface* psurface = SDL_GetWindowSurface(pwindow);
    
    const Uint32 BG_COLOR = SDL_MapRGBA(psurface->format, 255, 255, 0, 255);

    SDL_Rect rect = (SDL_Rect){WIDTH / 2, HEIGHT / 2, AGENT_SIZE, AGENT_SIZE};
    Agent* pagents = (Agent*) calloc(num_agents, sizeof(Agent));
    Agent agent0 = {WIDTH / 2, HEIGHT / 2 ,0xFF0000};
    int app_running = 1;
    SDL_Event event;
    while(app_running){
        while(SDL_PollEvent(&event)){
            if(event.type == SDL_QUIT){
                app_running = 0;
            }
        }
        /*
        for(int i = 0; i < num_agents; i++){
            //move_agent(psurface, pagents + i*sizeof(Agent));
            move_agent();

        }
        */
        move_agent(psurface, &agent0, BG_COLOR);

        SDL_UpdateWindowSurface(pwindow);
        SDL_Delay(20); // ~ 50 fps
    }

    return 0;
}
