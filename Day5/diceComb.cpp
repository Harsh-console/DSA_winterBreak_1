#include<bits/stdc++.h>
using namespace std;

long long MX = 1e9 + 7;

long long numWays_using_dice_ordered(int n){
    vector<long long> dp(n+1, 0);
    dp[0] = 1;
    vector<int> nums = {1, 2, 3, 4, 5, 6};
    for(int i = 1; i <= n; i++){
        for(int x : nums){
            if(i - x >= 0) dp[i] += dp[i - x] % MX;
        }
    }
    return dp[n];
}

int main(){
    int n;
    cin>>n;
    long long ans = numWays_using_dice_ordered(n) % MX;
    cout<<ans<<endl;
}

