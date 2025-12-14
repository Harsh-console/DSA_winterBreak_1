#include<bits/stdc++.h>
using namespace std;
int main() {
    int n, x;
    cin>>n>>x;
    vector<int> h(n); // prices of each books
    vector<int> s(n); // number of pages of each books
    for(int i = 0 ; i < n; i++) cin>>h[i];
    for (int i = 0; i < n; i++) cin>>s[i];

    // we want to read max. number of Pages in price of x
    // we could make dp[i] -> max. number of pages we could read in price of i
    // we could use bitmask on n(<= 1000) 2^1000 ~ 1e301 -> too much , bit mask directly not possible
    // state -> 1. number of pages read 2. price of books spent 3. books which are used
    // also greedy approach won't work

    // dp[i] -> maximum pages read only using the books indexed 0, 1, ..., i
    // (WRONG) dp[i+1] = max(dp[i], we include the new ith book, so price left = x - h[i], so its dp[x- h[i]]);
    // we make dp[i][j] -> maximum pages read only using books indexed 0, 1, ..., i and with maximum price j
    // x <= 10^5 -> dp ~ 10^8 not possible, but lets try!!!!
    /*
    vector<vector<int>> dp(n, vector<int> (x+1, s[0]));
    dp[0] = (h[0] >= x) ? (s[0]) : 0;
    for (int i = 0; i < n; i++) {
        if(h[i] > x){
            dp[i+1] = dp[i];
        }
        else{
            dp[i+1] = max(dp[i], dp[x - h[i]]);
        }
    }
    for (int i = 0; i < n; i++) dp[i][0] = 0;
    for (int i = 0; i < h[0]; i++) d[0][i] = 0;
    for (int new_book = 1; new_book < n; new_book++){
        for(int new_price = 1; new_price <= x; new_price++){
            
        }
    }

    //dp[i] = max. number of pages we could read with price atmost i
    //we iterate in reverse order from max cost to our budget cost  
    //dp[total cost of all books] = total number of pages of all books
    //dp[i - 1] = 
    */

    vector<vector<int>> dp(n+1, vector<int> (x+1));
    for (int i = 0; i <= x; i++) dp[0][i] = 0;
    for (int book = 1; book <= n; book++){
        for (int price = 1; price <= x; price++){
            if (h[book - 1] > price) dp[book][price] = dp[book - 1][price];
            else dp[book][price] = max(dp[book - 1][price], dp[book - 1][price - h[book - 1]] + s[book - 1]);
        }
    }
    cout<<dp[n][x]<<endl;
}
