#include<bits/stdc++.h>
using namespace std;

int countRooms(vector<vector<int>>& house, const int n, const int m);
vector<pair<int, int>> get_neighbors(const int x, const int y, const int n, const int m, vector<vector<int>>& house);
void tick_the_room(const int &floor_x, const int &floor_y, vector<vector<int>>& house, const int n, const int m,
        const int code);

int main(){
    int n, m;
    cin>>n>>m;
    vector<vector<int>> house(n, vector<int> (m, -1));
    char temp;
    pair<int, int> start;
    pair<int, int> end;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin>>temp;
            if(temp == '.'){
                house[i][j] = 0;
                continue;
            }
            if(temp == 'A'){
                house[i][j] = 0;
                start.first = j; start.second = i;
                continue;
            }
            if(temp == 'B'){
                house[i][j] = 0;
                end.first = j; end.second = i;
            }

        }
    }
    int ans = countRooms(house, n, m);
    bool isReachable = (house[start.second][start.first] == house[start.second][start.first]);
    if(isReachable) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}

int countRooms(vector<vector<int>>& house, const int n, const int m){
    //vector<vector<int>> tick = house;
    //house :- 0 ->undiscovered floor
    //house :- -1 -> wall
    //house :- i -> belong to ith room
    int floor_count = 1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(!house[i][j]){
                //cout<<"starting iteration"<<endl;
                tick_the_room(j, i, house, n, m, floor_count);
                floor_count += 1;
                //cout<<"floor count = "<<floor_count<<endl;
            }
        }
    }
    return floor_count - 1;
}

void tick_the_room(const int &floor_x, const int &floor_y, vector<vector<int>>& house, const int n, const int m,
        const int code){
    house[floor_y][floor_x] = code;
    vector<pair<int, int>> neighbors = get_neighbors(floor_x, floor_y, n, m, house);
    //cout<<"neighbors got!"<<endl;
    for(int i = 0; i < neighbors.size(); ++i){
        int x = neighbors[i].first, y = neighbors[i].second;
        if(house[y][x]) continue;
        house[y][x] = code;
        tick_the_room(x, y, house, n, m, code);
    }
}



vector<pair<int, int>> get_neighbors(const int x, const int y, const int n, const int m, vector<vector<int>>& house){
    vector<pair<int, int>> res;
    for(int i = -1; i < 2; i++) 
        for(int j = -1; j < 2; j++) 
            if((i*i + j*j) == 1) 
                if(x + i >= 0 && y + j >= 0 && x + i < m && y + j < n)
                    if(!house[y+j][x+i])
                        res.push_back({x+i, y+j});
    return res;
}

