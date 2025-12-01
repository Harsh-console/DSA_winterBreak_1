#include<bits/stdc++.h>
using namespace std;

const long long MX = 1e9 + 7;

long long countWays_ordered(int n, const vector<int> c){
    vector<long long> dp(n+1 ,0);
    dp[0] = 1;
    for(int i = 1; i <= n; i++){
        long long sum = 0;
        for(int x : c) if(i - x >= 0) sum += dp[i - x] % MX;
        dp[i] = sum % MX;
    }
    return dp[n];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, x;
    cin>>n>>x;
    vector<int> c(n);
    for(int &x : c) cin>>x;
    long long ans = countWays_ordered(x, c)  % MX;
    cout<<ans<<endl;
    return 0;
}

