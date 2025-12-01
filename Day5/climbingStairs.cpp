#include<bits/stdc++.h>
using namespace std;

long long num_ways(int n){
    vector<long long> dp(n+1, 0);
    dp[0] = 1;
    int steps[2] = {1, 2};
    for(int i = 1; i <= n; i++){
        for(int x : steps){
            if(i - x >= 0) dp[i] += dp[i - x];
        }
    }
    return dp[n];
}

int main(){
    int n;
    cin>>n;
    long long ans = num_ways(n);
    cout<<ans<<endl;
    return 0;
}

