#include<SDL2/SDL.h>
#include<fstream>
#include<iostream>
#include<vector>
#include<string>
#include<cassert>
using namespace std;

//note :- maximum number of pattern you could store(until the model give random memories) is approx. 0.14*n(where n = number of nuerons)
void calculate_weight(vector<vector<double>>& weight, vector<int>& storing_data){
    // set the weights w[i][j] so that given data has minimum energy level

    int n = weight.size();
    assert(weight.size()==n);
    for(int i = 0; i < n; i++){
        assert(weight[i].size() == n);
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i!=j){
                weight[i][j] += (storing_data[i])*(storing_data[j]);
            }
        }
    }
}

/*void find_best_x(vector<vector<int>>& weight, vector<int>& x, bool& is_converge){
    int n = weight.size();
    // weight[i][j] = weight of connection between the node(or neuron) i and j
    // here we assume symmetrical weights i.e., w[i][j] == w[j][i]
    // x[i] is state of neuron i which is 1 if x[i] is true ,and -1 if x[i] is false

    float min_increase = 0.01;
    vector<int>temp = x;
    if(!is_converge){
        // update all sets of neurons
        for(int i = 0; i < n; i++){
            int h_i = 0;
            for(int j = 0; j < n; j++){
                if(i != j){
                    h_i += (x[j]) * weight[i][j];
                }
            }
            if(h_i >= 0) temp[i] = 1;
            else temp[i] = -1;
            if(h_i < min_increase) is_converge = true;
            //cout<<h_i<<endl;
            cout<<"is_converge = "<<is_converge<<endl;
        }
        x = temp;
    }
}
*/

void find_best_x(const vector<vector<double>>& weight,
                 vector<int>& x,
                 bool& is_converge)
{
    int n = weight.size();

    // invariants (keep while debugging)
    // assert(x.size() == n);
    // for(int i = 0; i < n; i++) assert(weight[i].size() == n);

    vector<int> next = x;
    is_converge = true;   // assume convergence unless a neuron flips

    for(int i = 0; i < n; i++){
        double h_i = 0;
        for(int j = 0; j < n; j++){
            if(i != j)
                h_i += weight[i][j] * x[j];
        }

        int new_state = (h_i >= 0) ? 1 : -1;

        if(new_state != x[i])
            is_converge = false;

        next[i] = new_state;
    }

    x = next;
}

int main(int agrc, char* argv[]){
    bool is_converge = false;
    int num_memories;
    bool do_remember = false;
    bool isMouseDown = false;
    SDL_Init(SDL_INIT_VIDEO);
    const int WIDTH = 600, HEIGHT = 600, GRID_SIZE = 60;
    const int numX = WIDTH / GRID_SIZE, numY = HEIGHT / GRID_SIZE;

    SDL_Window* window = SDL_CreateWindow("Drawing Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
    //SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    int running = 1;
    vector<int> data(numX*numY, -1);
    SDL_Event event;
    SDL_Rect rect = {-GRID_SIZE, -GRID_SIZE, GRID_SIZE, GRID_SIZE};
    SDL_SetRenderDrawColor(renderer, 255, 165, 50, 255);
    vector<vector<double>> weight(numX*numY, vector<double> (numX*numY, 0));
    int i, j;
 
    while(running){

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
                if(isMouseDown) 
                    if(event.motion.y >= 0 && event.motion.y < HEIGHT && event.motion.x >= 0 && event.motion.x < WIDTH){
                        //cout<<"position is : "<<(event.motion.y / GRID_SIZE)*numX + (event.motion.x / GRID_SIZE)<<endl;
                        data[(event.motion.y / GRID_SIZE)*numX + (event.motion.x / GRID_SIZE)] = 1;
                    }
            }
            if(event.type == SDL_KEYDOWN){
                if(event.key.keysym.sym == SDLK_ESCAPE){
                    //running = false;
                    do_remember = true;
                }
            }
 
        }

        // draw using data
        SDL_SetRenderDrawColor(renderer, 255, 165, 50, 255);
        for(int k = 0; k < numX*numY; k++){
            if(data[k] == 1){
                j = k / numX;
                i = k % numX;
                rect.x = i*GRID_SIZE;
                rect.y = j * GRID_SIZE;
                SDL_RenderFillRect(renderer, &rect);
            }
        }
        
        // remember the from data available
        if(do_remember){
            //clear the weights before learning
            for(int i = 0; i < numX*numY; i++){
                for(int j = 0; j < numX*numY; j++){
                    weight[i][j] = 0;
                }
            }
            //{
                //calculate the weight
                ifstream inFile;
                inFile.open("num_memories.txt");
                inFile>>num_memories;
                inFile.close();
                cout<<"Number of memories = "<<num_memories<<endl;
                for(int num = 1; num <= num_memories; num++){
                    string file_name = "data" + to_string(num) + ".txt";
                    inFile.open(file_name);
                    if(!inFile){
                        cerr << "FAILED to open " << file_name << endl;
                    }
                    vector<int> inData;
                    int temp;
                    while(inFile>>temp){
                        inData.push_back(temp);
                    }
                    cout<<inData.size();
                    cout << "Expected: " << numX*numY << "  Got: " << inData.size() << endl;

                    calculate_weight(weight, inData);
                    assert(inData.size() == numX * numY);
                    inFile.close();
                }

            //}
            cout<<"weights : \n";
            for(int i = 0; i < numY; i++){
                for(int j = 0; j < numX; j++){
                    cout<<weight[i][j]<<" ";
                }
                cout<<"\n";
            }
            //exit(0);

            {
                // guess the memory
                find_best_x(weight, data, is_converge);
                
                
            }

            if(is_converge) do_remember = false;
        }

        SDL_RenderPresent(renderer);
    }

    return 0;
}
