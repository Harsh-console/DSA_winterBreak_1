#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int count_ways(const vector<vector<int>> &grid){
    int n = grid.size();
    vector<vector<int>> dp(n, vector<int> (n, 0));

    //dp[0][0] = grid[0][0];
    // first row
    for(int i = 0; i < n; i++){
        if (grid[i][0]) dp[i][0] = 1;
        else break;
    }
    // first column
    for(int j = 0; j < n; j++){
        if(grid[0][j]) dp[0][j] = 1;
        else break;
    }

    // remaining dp
    for(int i = 1; i < n; i++){
        for(int j = 1; j < n; j++){
            if(grid[i][j]) dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % MOD;
        }
    }
    return dp[n-1][n-1] % MOD;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;

    vector<vector<int>> grid(n, vector<int> (n, 0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            char val; cin >> val;
            if(val == '.') grid[i][j] = 1;
        }
    }
    int ans = count_ways(grid);
    cout<<ans<<endl;
}
