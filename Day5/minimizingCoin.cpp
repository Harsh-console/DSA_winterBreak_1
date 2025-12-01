#include<bits/stdc++.h>
using namespace std;

long long minimum_num_of_ways(int n, vector<int> &c){
    const long long INF = 1e18;
    vector<long long> dp(n+1, INF); //dp[i] contain minimum number of coins required to reach sum = i
    dp[0] = 0;
    for(int i = 1; i <= n; i++){
        //vector<int> nums;
        long long best = INF;
        for(int x : c){
            if(i - x >= 0 && dp[i - x] != INF){
                //nums.push_back(dp[i - x]);
                if(dp[i - x] < best) best = dp[i - x];
            }
        }
        if(best == INF) continue;
        //sort(nums.begin(), nums.end());
        dp[i] = best + 1;
    }
    return dp[n] == INF ? -1 : dp[n];
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
    long long ans = minimum_num_of_ways(_sum, c);
    cout<<ans<<endl;
}


