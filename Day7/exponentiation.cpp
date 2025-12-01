#include<bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;

long long exp(long long a, long long b){
    // base condition
    if(b == 1) return a;
    if(b == 0) return 1;
    long long ans = exp(a, b / 2);
    ans = (ans*ans) % MOD;
    if(b&1) ans = (ans * a ) % MOD;
    return ans % MOD;
}

int main(){
    int n;
    cin>>n;
    for(int i = 0; i < n; i++){
        long long a, b;
        cin>>a;
        cin>>b;
        long long ans = exp(a, b);
        cout<<ans<<endl;
    }
    return 0;
}
