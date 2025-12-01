#include<bits/stdc++.h>
using namespace std;

long long binexp(long long a, long long b, long long MOD){
    a %= MOD;
    long long res = 1;
    while(b){
        if(b&1) res = (res * a) % MOD;
        b>>=1;
        a = (a * a) % MOD;
    }
    return res;
}

int main(){
    const long long MOD = 1e9+7;
    int n;
    cin>>n;
    for(int i = 0; i < n; i++){
        int a, b, c;
        cin>>a>>b>>c;
        long long exp_mod = binexp(b, c, MOD - 1); // fermat's principle
        long long ans = binexp(a, exp_mod, MOD);
        cout<<ans<<endl;
    }
}
