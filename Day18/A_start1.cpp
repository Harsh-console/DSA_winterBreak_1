#include<SDL2/SDL.h>
#include<vector>
#include<iostream>
using namespace std;

const int WIDTH = 600;
const int HEIGHT = 600;

void drawMap(vector<vector<int>>& m, SDL_Renderer*& renderer, SDL_Rect& rect);
bool InitSDL(SDL_Window*& window, SDL_Renderer*& renderer, const int& WIDTH, const int& HEIGHT);
void ClearSDL(SDL_Window*& window, SDL_Renderer*& renderer);
void ClearScreen(SDL_Renderer*& renderer, const SDL_Color &BackgrondColor);
vector<pair<int, int>> getNeighbors(pair<int, int> current, vector<vector<int>> &m);
void isBelong(vector<pair<int, int>>& negihbors, pair<int, int>& current);
void solve(pair<int, int>& target, vector<vector<int>>& m);

int main(int argv, char* argc[]){
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;

    
    if(!InitSDL(window, renderer, WIDTH, HEIGHT)) return 0;
    
    vector<vector<int>> m = {
        {0,0,0,0,0,0},
        {0,2,0,-1,0,0},
        {0,0,0,-1,0,0},
        {0,-1,-1,-1,0,0},
        {0,0,0,0,3,0},
        {0,0,0,0,0,0}
    };
    // 0 :- allowed -> white
    // -1 :- obstacle -> black
    // 2 :- start point -> purple
    // 3 :- target -> orange
    
    // Draw Map
    SDL_Rect rect;
    drawMap(m, renderer, rect);
    
    int running = 1;
    SDL_Event event;
    while(running){
        while(SDL_PollEvent(&event)){
            if(event.type == SDL_QUIT){
                running = 0;
            }
        }
        SDL_RenderPresent(renderer);
    }
    ClearSDL(window, renderer);

    return 0;
}


bool InitSDL(SDL_Window*& window, SDL_Renderer*& renderer, const int& WIDTH, const int& HEIGHT){
    // 1. Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cout << "SDL Init Error: " << SDL_GetError() << std::endl;
        return false;
    }

    // 2. Create Window
    window = SDL_CreateWindow(
        "A* Algorithm",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        WIDTH,
        HEIGHT,
        SDL_WINDOW_SHOWN
    );
    if (!window) {
        std::cout << "Window Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return false;
    }
    // 3. Create Renderer
    renderer = SDL_CreateRenderer(
        window,
        -1,
        SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
    );

    if (!renderer) {
        std::cout << "Renderer Error: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return false;
    }

    return true;
}


void ClearSDL(SDL_Window*& window, SDL_Renderer*& renderer){
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void ClearScreen(SDL_Renderer*& renderer, const SDL_Color &BackgrondColor){
    SDL_SetRenderDrawColor(renderer, BackgrondColor.r, BackgrondColor.g, BackgrondColor.b, BackgrondColor.a); //black color
    SDL_RenderClear(renderer);
}

void drawMap(vector<vector<int>>& m, SDL_Renderer*& renderer, SDL_Rect& rect){
    const int GRID_X = WIDTH / m[0].size();
    const int GRID_Y = HEIGHT / m.size();
    rect.w = GRID_X;
    rect.h = GRID_Y;
    for(int i = 0; i < m[0].size(); i++){
        for(int j = 0; j < m.size(); j++){
            rect.x = i * GRID_X;
            rect.y = j * GRID_Y;
            if(m[j][i] >= 0){
                switch(m[j][i]){
                    case 0:
                        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
                        break;
                    case 2:
                        SDL_SetRenderDrawColor(renderer, 128, 0, 128, 255);
                        break;
                    case 3:
                        SDL_SetRenderDrawColor(renderer, 255, 165, 0, 255);
                        break;
                    default:
                        break;
                }
                SDL_RenderFillRect(renderer, &rect);
            }
        }
    }
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    for(int i = 1; i <= m[0].size(); i++) SDL_RenderDrawLine(renderer, i * GRID_X, 0, i * GRID_X, HEIGHT);
    for(int i = 1; i <= m.size(); i++) SDL_RenderDrawLine(renderer, 0, i * GRID_Y, WIDTH, i * GRID_Y);
}

vector<pair<int, int>> getNeighbors(pair<int, int> current, vector<vector<int>> &m){
    static int numX = m[0].size();
    static int numY = m.size();
    vector<pair<int, int>> neighborsLocal;
    vector<pair<int, int>> neighbors;
    for(int i = -1; i <= 1; i++){
        for(int j = -1; j <= 1; j++){
            if(i*i + j*j !=0){
                if(((current.first + i >= 0) && (current.second + j >= 0)) && ((current.first + i < numX) && (current.second + j < numY))){
                    neighborsLocal.push_back({current.first+i, current.second+j});
                }
            }
        }
    }
    for(pair<int, int>& neighbor : neighborsLocal){
        if(!m[neighbor.second][neighbor.first]){
            neighbors.push_back(neighbor);
        }
    }
    return neighbors;
}

void isBelong(vector<pair<int, int>>& negihbors, pair<int, int>& current){
    bool isPresent = false;
    for(int i = 0; i < neighbors.size(); i++){
        if(neighbors[i].first != current.first || neighbors[i].second != second);
        else{
            isPresent = true;
        }
    }
    return isPresent;
}

void solve(pair<int, int>& target, vector<vector<int>>& m){
    static int tempX, tempY;
    static int tempPathLength;
    vector<pair<int, int>> open; // the set of nodes to be evaluated
    vector<pair<int, int>> closed; //the set of nodes already evaluated
    while(true){
        pair<int, int>::iterator current ; // node of open with lowest f value
        tempX = current->first;
        tempY = current->second;
        open.erase(current); // remove current from open
        closed.push_back({tempX, tempY}); //add current to closed

        if(tempX == target.x && temp.Y == target.y){
            return;
        }
        
        vector<pair<int, int>> neighbors = GetNeighbors(current, m);

        for(const pair<int, int>& neighbor : neighbors){
            if(isBelong(neighbors, current) || notTransversable(current, target, m)){
                continue;
            }
            tempPathLength = calcPathLength(m, current)
            if(tempPathLength < 
        }

    }
}
