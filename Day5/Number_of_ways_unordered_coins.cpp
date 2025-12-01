#include<bits/stdc++.h>
using namespace std;

long long countWays(int n, vector<int> &c){
    vector<long long> dp(n+1, 0);
    dp[0] = 1;
    for(int coin : c){
        for(int cnt = coin; cnt <= n; cnt++){
            dp[cnt] += dp[cnt - coin];
        }
    }
    return dp[n];
}

int main(){
    int n, _sum;
    cin>>n>>_sum;
    vector<int> c;
    for(int i = 0; i < n; i++){
        int val;
        cin>>val;
        c.push_back(val);
    }
    long long ans = countWays(_sum, c);
    cout<<ans<<endl;
}

