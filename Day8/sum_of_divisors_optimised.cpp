#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int sum_of_sum_of_div(int n){
    int sum = 0;
    for(int d = 1; d <= n; d++){
        sum += (d) * (n / d);
        if(sum > MOD) sum = (sum % MOD);
    }
    return sum % MOD;
}

int main(){
    int n;
    cin>>n;
    long long ans = sum_of_sum_of_div(n);
    cout<<ans<<endl;
}

