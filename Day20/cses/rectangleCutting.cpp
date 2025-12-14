#include<bits/stdc++.h>
using namespace std;

int num_of_cutting(int n, int m){
    const int INF = 1e9;
    vector<vector<int>> dp(n+1, vector<int> (m+1));// dp[i][j] -> min. number of moves for ixj rectangle
    for(int i = 0; i <= min(n, m); i++) dp[i][i] =0; //already a square
    for(int i = 0; i <= n; i++) dp[i][0] = 0;
    for(int j = 0; j <= m; j++) dp[0][j] = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            // we want to find dp[i][j] = min. no. of moves for i * j, now, if we make any cut we know the answer, so make all cuts
            // and find the answer
            int ans = INF;
            if(i == j){
                dp[i][j] = 0;
                continue;
            }
            // we have i squares, so number of possible cuts = i - 1 from cut = 1 to cut = i-1
            for(int cut = 1; cut < i; cut++) ans = min(ans, 1 + dp[cut][j] + dp[i - cut][j]);
            for(int cut = 1; cut < j; cut++) ans = min(ans, 1 + dp[i][cut] + dp[i][j - cut]);
            dp[i][j] = ans;
        }
    }
    return dp[n][m];
    /*
     * this fails as it don't take into account of multiple cutting
    int cnt = 0;
    while(a != b){
        if(a > b){
            a-=b;
            cnt++;
        }
        else {
            b-=a;
            cnt++;
        }
    }
    return cnt;
    */
}

int main(){
    int a, b;
    cin>>a>>b;
    cout<<num_of_cutting(a, b)<<endl;
}
