#include<bits/stdc++.h>
using namespace std;

void longestCommonSubsequence(int a[], int b[], int n, int m){
    vector<vector<int>> dp(n+1 ,vector<int> (m+1));
    for(int i = 0; i < n; i++) dp[i][0] = 0;
    for(int j = 0; j < m; j++) dp[0][j]=0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(a[i-1] == b[j-1]){
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
        }
    }
    cout<<dp[n][m]<<endl;
    //back track for find the longest subsequence
    int i = n, j = m;
    vector<int> lcs;
    while(i > 0 && j > 0){
        if(a[i-1] == b[j - 1]){
            lcs.push_back(a[i-1]);
            i--; j--;
        }
        else if (dp[i-1][j] > dp[i][j-1]){
            i--;
        }
        else j--;
    }
    reverse(lcs.begin(), lcs.end());
    for(int i = 0; i < lcs.size(); i++) cout<<lcs[i]<<" ";
}

int main(){
    int n, m; 
    cin>>n>>m;
    int a[n];int b[m];
    for(int i = 0; i < n; i++) cin>>a[i];
    for(int j = 0; j < m; j++) cin>>b[j];
    longestCommonSubsequence(a, b, n, m);
}

