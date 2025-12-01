#include<bits/stdc++.h>
using namespace std;
/*
vector<int> produce_primes(int MX){
    bool isPrime[MX+1] = {true}; // arr[i] ~> i 
    isPrime[0] = false;
    isPrime[1] = false;
    int n = 2;
    while(n < MX){
        int num = n;
        while(num <= MX){
            isPrime[num] = false;
            num+=n;
        }
        int next = n+1;
        while(!isPrime[next]) next++;
        if(next >= MX) break;
        n = next;
    }
    vector<int> primes;
    for(int i = 2; i < MX; i++) if(isPrime[i]) primes.push_back(i);
    return primes;
}


void printVector(vector<int> &vec){
    for(int x : vec){
        cout<<x<<endl;
    }
}
*/
int main(){
    int n;
    cin>>n;
    while(n--){
        int x;
        cin>>x;
        int div = 1;
        int i = 2;
        for(; i * i <= x; i++){
            if(x % i == 0) div++;
        }
        div *= 2;i--;
        if(x == i*i) div--;
        cout<<div<<endl;
    }
    // ex- 30
    // 30 -> 2 x 3 x 5
    // number of divisors = 8
    // sqrt(30) = 5.something
    // 1, 2, 3, 5 < sqrt(30)
    // 1 - 30
    // 2 - 15
    // 3 - 10
    // 5 - 6
    // 25 -> 1, 5
    // 2 * 2 = 4
}
