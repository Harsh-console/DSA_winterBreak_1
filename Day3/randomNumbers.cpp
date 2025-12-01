#include<bits/stdc++.h>
#define ll long long
using namespace std;
mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

ll getRand64(){
    return rng();
}

ll my_rand(){
    ll a = rand();
    ll b = rand();
    return a * (RAND_MAX + 1LL) + b;
}

int main(){
    ll a = my_rand();
    ll b  = getRand64();
    cout<<"Two Random Numbers are : " << endl <<a << endl << b<<endl;
    return 0;
}

