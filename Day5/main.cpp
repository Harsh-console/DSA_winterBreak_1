#include<bits/stdc++.h>
using namespace std;

int fibRecursive(int n){
    if(n < 2) return n;
    return fibRecursive(n - 1) + fibRecursive(n - 2);
}

int fibIterative(int n){
    int memo[n+2] = {0};
    memo[0] = 0; memo[1] = 1;
    for(int i = 2; i <= n; i++){
        //memo[i + 1] += memo[i];
        //memo[i + 2] += memo[i];
        memo[i] = memo[i - 1] + memo[i - 2];
    }
    return memo[n];
}



int main(){
    bool isSame = true;
    int n = 20;
    for(int i = 0; i < n; i++){
        if(fibRecursive(i) != fibIterative(i)){
            isSame = false;
            cout<<"Inaccuracy at i = "<<i<<endl;
        }   
    }
    if(isSame) cout<<"Yes, both methods are correct!"<<endl;
    else cout<<"No, atleast one of the methods is incorrect!"<<endl;
    return 0;
}
