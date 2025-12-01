#include<bits/stdc++.h>
using namespace std;

long long num_ways_with_limited_jumps(int n, int k){
    vector<vector<long long>> dp(n+1, vector<int, int>(k+1, 0));
    dp[0][0] = 1;
    int steps[2] = {1, 2};
    for(int i = 1; i <= n; i++){
        for(int m = 1; m <= k; m++){
            for(int x : steps){
                if(i - x >= 0 && dp[i]) dp[i][m] += dp[i - x][m - 1] + dp[i - x][m - 2];
            }
        }
    }
    return dp[n];
}

int main(){
    int n, k;
    cin>>n>>k;
    long long ans = num_ways_with_limited_jumps(n, k);
    cout<<ans<<endl;
    return 0;
}

