#include<bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;

int count_matching(vector<vector<int>> &matrix){
    int n = matrix.size();
    long long dp[1<<n] = {0}; // dp[mask] = number of ways to match first k men where mask denote the women who are selected
    dp[0LL] = 1; // no men assigned yet, hence empty
    for(int mask = 0LL; mask < (1LL<<n); mask++){
        int k = __builtin_popcountll(mask);
        for(int women = 0; women < n; women++){
            if((k < n) && ((mask & (1<<women)) == 0) && matrix[k][women ]){
                long long newMask = mask | (1<<women);
                dp[newMask] = (dp[newMask] + dp[mask]) % MOD; 
            }
        } 
    }
    return dp[(1<<n) - 1];
}

int main(){
    int n;
    cin>>n;
    vector<vector<int>> __matrix;
    for(int i = 0; i < n; i++){
        vector<int> dummy_vector(n);
        for(int j = 0; j < n; j++){
            cin>>dummy_vector[j];
        }
        __matrix.push_back(dummy_vector);
    }
    int ans = count_matching(__matrix);
    cout<<ans<<endl;
}
