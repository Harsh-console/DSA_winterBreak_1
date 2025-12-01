#include<bits/stdc++.h>
using namespace std;
/*
void minimum_sum_path(int n, int arr[n][n], pair<int, int> ans[n]){
    vector<vector<int>> dp(n, vector<int> (n, 0));
    dp[0][0] = arr[0][0];
    int step = 0;
    ans[0] = {0, 0};
    // update values of dp for 1st row and 1st column.
    for(int i = 1; i < n; i++){
        
    }
    for(int i = 1; i < n; i++){
        for(int j = 1; j < n; j++){
            dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + arr[i][j];
            ans[step++] = dp[i - 1][j] > dp[i][j - 1] ? {i - 1, j} : {i, j - 1};
        }
    }
}
*/

pair<int, vector<pair<int, int>>> minimum_sum_path(vector<vector<int>> arr){
    int n = arr.size();
    vector<pair<int, int>> dp(n, vector<int> (n, 0)); //dp[i][j] = minimum sum to reach (i, j)
    vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>> (n, {0, 0})); // parent[i][j] = parent of cell (i, j)

    dp[0][0] = arr[0][0];
    
    // update dp for 1st column
    for(int i = 1; i < n; i++){
        dp[i][0] = dp[i - 1][0] + arr[i][j];
        parent[i][0] = {i - 1, 0};
    }

    // update dp for 1st row
    for(int j = 1; j < n; j++){
        dp[0][j] = dp[0][j - 1] + arr[0][j];
        parent[0][j] = {0, j - 1};
    }

    // rest of the loop for dp
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(dp[i - 1][j] < dp[i][j - 1]){
                dp[i][j] = dp[i - 1][j] + arr[i][j];
                parent[i][j] = {i - 1, j};
            }
            else{
                dp[i][j] = dp[i][j - 1] + arr[i][j];
                parent[i][j] = {i, j - 1};
            }
        }
    }

    vector<pair<int, int>> path;
    int i = n - 1; j = n - 1;
    while(i >= 0 && j >= 0){
        path.push_back({i, j});
        tie(i, j) = parent[i][j];
    }
    return {dp[n][n], path};
}
