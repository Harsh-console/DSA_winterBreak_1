#include<bits/stdc++.h>
using namespace std;
int main(){
    const int MOD = 1e9 + 7;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin>>n>>m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin>>a[i];
    
    // given a number the adjacent number has only three choice, increase, decrease or remain same
    // all number has to be in range [1, m]
    // there are total of n numbers, diff of any to adj ones are atmost one
    // at each point we should check if there exist the solution and its easy to check. just take difference of numbers and difference between the indeces. if indices are i and j(both of which values are known), then solution exists if abs(a[i] - a[j]) <= abs(i - j)
    // we could do this easily by recursive dp, but it could cause stack overflow, as there could be many many possiblilities, iterative dp would be better
    // let total number of unknown numbers be u.
    // bit masking could not work as m <= 100 and 2^100 ~ 10^30, and we have three choices.
    //dp[i][v] = number of ways to fill array upto index i with a[i] = v
    vector<vector<int>> dp(n, vector<int> (m+2));
    if(!a[0]) for(int i = 1; i <= m+1; i++) dp[0][i] = 1;
    else for(int i = 1; i <= m+1; i++) dp[0][i] = (a[0] == i);
    dp[0][m+1] = 0;
    for(int i = 0; i < n; i++) dp[i][0] = 0;
    //for(int i = 0; i < n; i++) dp[i][m+1] = 0;
    for (int i = 1; i < n; i++){
        if(a[i]){
            // update all v for i = i
            for(int v = 1; v <= m; v++){
                if(a[i] != v) dp[i][v] = 0;
                else dp[i][v] = ((dp[i - 1][v] + dp[i - 1][v - 1])%MOD + dp[i - 1][v + 1] )% MOD;
            }
        }
        else {
            for(int v = 1; v <= m; v++) {
                dp[i][v] = ((dp[i - 1][v] + dp[i - 1][v - 1])%MOD + dp[i - 1][v + 1]) % MOD;
            }
        }
    }
    long long ans = 0;
    for(int v = 1; v <= m; v++) {
        ans += dp[n-1][v];
        ans = ans % MOD;
    }
    cout<<(ans%MOD)<<endl;
    return 0;
}
