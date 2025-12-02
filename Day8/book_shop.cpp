#include<bits/stdc++.h>
using namespace std;

int max_page(int budget, vector<int> &pages, vector<int> &price){
    int n = price.size();
    // state of dp is we have spent x money, what is maximum number of pages we get.
    vector<int> dp(budget+1, 0);
    dp[0] = 0;
    for(int i = 0; i < n; i++){
        for(int book = budget; book >= price[i]; book--){
            dp[book] = max(dp[book], price[i] + dp[book - price[i]]);
        }
    }
    return dp[n];
}

int main(){
    int n;
    cin>>n;
    vector<int> price(n, 0);
    vector<int> pages(n);
    int budget; cin>>budget;
    for(int i = 0; i < n; i++) cin>>price[i];
    for(int i = 0; i < n; i++) cin>>pages[i];
    int ans = max_page(budget, pages, price);
    cout<<ans<<endl;
}
