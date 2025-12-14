#include<bits/stdc++.h>
using namespace std;
int main(){
    int tt;
    const int MOD = 1e9 + 7;
    cin>>tt;
    vector<int> test(tt);
    for(int i = 0; i < tt; i++) cin>>test[i];
    map<int, long long> storage;
    for(int j = 0; j < tt; j++) {
        int n = test[j];
        if(storage.find(n)!=storage.end()){
            auto it = storage.find(n);
            cout<<it->second<<endl;
            continue;
        }
        vector<long long> a(n+1); // if last row has both block in same block
        vector<long long> b(n+1); // if in last row has both block in different blocks
        //a[i]  = 2 * a[i-1] + b[i-1]
        //b[i] = a[i - 1] + 4 * b[i-1]
        a[1] = 1;
        b[1] = 1;
        for(int i = 2; i<=n;i++){
            a[i] = ((2*a[i-1]) %MOD + b[i-1]) % MOD;
            b[i] = (a[i-1] + (4*b[i-1]) % MOD) % MOD;
        }
        cout<<(a[n]+b[n])%MOD<<endl;
        storage[n] = (a[n] + b[n])%MOD;
    }
    return 0;
}
