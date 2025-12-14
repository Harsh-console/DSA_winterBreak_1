#include<iostream>
#include<vector>
#include<stack>

struct Cell{
    int x;
    int y;
};

class RoomCounter{
public:
    RoomCounter(int n, int m, std::vector<std::vector<int>>& grid) :rows(n), cols(m), house(grid) {}
    int countRooms(){
        int roomId = 1;
        for(int y = 0; y < rows; ++y){
            for(int x = 0; x < cols; ++x){
                if(house[y][x] == FLOOR_UNVISITED){
                    floodFill(x, y, roomId);
                    roomId++;
                }
            }
        }
        return roomId - 1;
    }
private:
    static constexpr int WALL = -1;
    static constexpr int FLOOR_UNVISITED = 0;
    
    int rows;
    int cols;
    std::vector<std::vector<int>> house;

    void floodFill(int startX, int startY, int roomId){
        std::stack<Cell> stack;
        stack.push({startX, startY});
        house[startY][startX] = roomId;

        const int dx[4] = {1, -1, 0, 0};
        const int dy[4] = {0, 0, -1, 1};
        while(!stack.empty()){
            auto [x, y] = stack.top();
            stack.pop();
            for(int dir = 0; dir < 4; ++dir){
                int nx = x + dx[dir];
                int ny = y + dy[dir];

                if(isInside(nx, ny) && house[ny][nx] == FLOOR_UNVISITED){
                    house[ny][nx] = roomId;
                    stack.push({nx, ny});
                }
            }
        }
    }
    bool isInside(int x, int y) const {
        return (x >= 0 && y >= 0 && x < cols && y < rows);
    }
};

int main(){
    int n, m;
    std::cin>>n>>m;
    
    std::vector<std::vector<int>> house(n, std::vector<int>(m, -1));

    for(int y = 0; y < n; ++y){
        for(int x = 0; x < m; ++x){
            char c;
            std::cin>>c;
            if(c == '.'){
                house[y][x] = 0; //floor unvisited
            }
        }
    }

    RoomCounter solver(n, m, house);
    std::cout<<solver.countRooms()<<std::endl;
    return 0;
}
