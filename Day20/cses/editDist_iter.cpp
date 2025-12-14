#include<bits/stdc++.h>
using namespace std;
int lev(string a, string b) {
    // we modify a to become b
    int n = a.size();
    int m = b.size();
    vector<vector<int>> dp(n+2, vector<int>(m+1, 0));
    //dp[i][j] -> dist between a[:i] and b[:j]
    for(int i = 0; i <= m; i++) dp[0][i] = i;
    for(int i = 0; i <= n; i++) dp[i][0] = i;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(a[i-1] == b[j-1]) dp[i][j] = dp[i - 1][j - 1];
            else dp[i][j] = 1 + min(min(
                    dp[i-1][j], // delete
                    dp[i][j-1]), // add
                    dp[i-1][j-1] //replace
                    );
        }
    }
    return dp[n][m];
}
int main(){
    string a, b;
    cin>>a>>b;
    cout<<lev(a, b)<<endl;
}

