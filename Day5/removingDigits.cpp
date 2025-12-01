#include<bits/stdc++.h>
using namespace std;

int largestDigit(int n){
    int best = 0;
    while(n){
        best = max(best, n % 10);
        n /= 10;
    }
    return best;
}

long long num_steps(int n){
    long long steps = 0;
    while(n){
        n -= largestDigit(n);
        steps++;
    }
    return steps;
}

int main(){
    int n;
    cin>>n;
    long long ans = num_steps(n);
    cout<<ans<<endl;
    return 0;
}
