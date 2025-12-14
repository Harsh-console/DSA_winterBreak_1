#include<SDL2/SDL.h>
#include<bits/stdc++.h>
using namespace std;

struct Node {
    int x, y;
};

template<int H, int W>
vector<Node> shortestPath(
    bool (&grid)[H][W],   // real 2D array
    int startX, int startY,
    int endX, int endY
) {
    const int numY = H;
    const int numX = W;

    static const int dx[4] = {1, -1, 0, 0};
    static const int dy[4] = {0, 0, 1, -1};

    vector<vector<bool>> visited(numY, std::vector<bool>(numX, false));
    vector<vector<Node>> parent(numY, std::vector<Node>(numX, {-1, -1}));

    queue<Node> q;
    q.push({startX, startY});
    visited[startY][startX] = true;

    bool found = false;

    while (!q.empty()) {
        Node cur = q.front();
        q.pop();

        if (cur.x == endX && cur.y == endY) {
            found = true;
            break;
        }

        for (int i = 0; i < 4; i++) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];

            if ((unsigned)nx < numX &&
                (unsigned)ny < numY &&
                grid[ny][nx] &&      // true = floor
                !visited[ny][nx])
            {
                visited[ny][nx] = true;
                parent[ny][nx] = cur;
                q.push({nx, ny});
            }
        }
    }

    if (!found)
        return {};

    vector<Node> path;

    for (Node cur = {endX, endY}; cur.x != -1; cur = parent[cur.y][cur.x])
        path.push_back(cur);

    reverse(path.begin(), path.end());
    return path;
}

int main(int argv, char* argc[]){
    SDL_Init(SDL_INIT_VIDEO);
    const int WIDTH = 1200, HEIGHT = 600, GRID_SIZE = 30;
    const int numX = WIDTH / GRID_SIZE, numY = HEIGHT / GRID_SIZE;

    SDL_Window* window = SDL_CreateWindow("Drawing Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
    //SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    int running = 1;
    SDL_Event event;
    
    bool pixel[numY][numX];
    for(int y = 0; y < numY; ++y){
        for(int x = 0; x < numX; ++x){
            pixel[y][x] = true;
        }
    }

    SDL_Rect rect = {-1, -1, GRID_SIZE, GRID_SIZE};
    bool isMouseDown = false;
    bool isDrawPath = false;
    vector<Node> path;

    Uint32 lastTime = SDL_GetTicks();
    int frames = 0;
    int fps = 0;

    while(running){
        //SDL_Delay(10);
        
        //Clear Screen
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

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
                if(isMouseDown) if(event.motion.y >= 0 && event.motion.y < HEIGHT)pixel[event.motion.y / GRID_SIZE][event.motion.x / GRID_SIZE] = false;
            }
            if(event.type == SDL_KEYDOWN){
                if(event.key.keysym.sym == SDLK_ESCAPE){
                    path = shortestPath(pixel, 0, 0, numX - 1, numY - 1);
                    isDrawPath = true;

                }
            }
        }
        
        if(isDrawPath){
            SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
            for(auto& node : path){
                rect.x = node.x * GRID_SIZE, rect.y = node.y * GRID_SIZE;
                SDL_RenderFillRect(renderer, &rect);
            }
        }
        SDL_SetRenderDrawColor(renderer, 255, 165, 0, 255);
        for(int y = 0; y < numY; ++y){
            for(int x = 0; x < numX; ++x){
                if(!pixel[y][x]){
                    rect.x = x  * GRID_SIZE; rect.y = y * GRID_SIZE;
                    SDL_RenderFillRect(renderer, &rect);
                }
            }
        }
        SDL_RenderPresent(renderer);
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
