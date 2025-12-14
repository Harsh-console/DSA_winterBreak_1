#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<vector<int>> pos(n, vector<int>(n));
    int x, y;
    for(int i = 0; i < n; i++){
        cin>>x>>y;
        pos[i][0] = x;
        pos[i][1] = y;
    }
    int min_M = 1e9+7;
    for(int x = 1; x < n;x++){
        for(int y = 1; y < n; y++){
            vector<vector<int>> M_(2, vector<int> (2, 0));
            for(int i = 0; i < n; i++){
                M_[pos[i][0] > x][pos[i][1] > y]++;
            }
            int max_val;
            max_val = max(max(M_[0][0], M_[0][1]), max(M_[1][0], M_[1][1]));
            min_M = min(min_M, max_val);
        }
    }
    cout<<min_M<<endl;
    return 0;
}
