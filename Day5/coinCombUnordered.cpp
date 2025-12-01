#include<bits/stdc++.h>
using namespace std;

const long long MX = 1e9 + 7;

long long count_ways_unordered(const int n, const vector<int> &nums){
    vector<long long> dp(n+1, 0);
    dp[0] = 1;
    for(int x : nums){
        for(int s = x; s <= n; s++){
            dp[s] += (dp[s - x] % MX);
        }
    }
    return dp[n] % MX;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, x;
    cin>>n>>x;
    vector<int> coins(n);
    for(int &x : coins) cin>>x;
    long long ans = count_ways_unordered(x, coins);
    cout<<ans<<endl;
}

