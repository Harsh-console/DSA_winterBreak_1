#include<iostream>
#include<vector>
#include<random>
using namespace std;

class Grid{
    private:
        int max_sizeX, max_sizeY;
        int maxX = -1; int maxY = -1;
        vector<vector<int>> grid;
    public:
        Grid(pair<int, int> max_Size_G, pair<int, int> max_Size_init){
            this->max_sizeX = max_Size_G.first;
            this->max_sizeY = max_Size_G.second;
            this->maxX = max_Size_init.first;
            this->maxY = max_Size_init.second;
        }
        Grid(pair<int, int> p){
            this->max_sizeX = p.first;
            this->max_sizeY = p.second;
            this->maxX = p.first;
            this->maxY = p.second;
        }
        void printGrid(){
            int x = maxX;
            int y = maxY;
            while(y >= 0){
                while(x >= 0){
                    cout<<grid[x--][y]<<" ";
                }
                y--;
                cout<<'\n';
            }
        }
        void insert(int x, int y){
            
        }
        void set_max(int x, int y) {
            this->max_X = x; 
            this->max_Y = y;
        }
        void set_maxX(int x) {
            this->max_X = x;
        }
        void set_maxY(int y){
            this->max_Y = y;
        }
        void isEmpty(){
            return (this->grid).size() == 0;
        }
        void isFull(){
            return ((this->maxX) == (this->max_sizeX) || (this->maxY == this->max_sizeY));
        }
};

