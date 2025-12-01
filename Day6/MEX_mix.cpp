#include<bits/stdc++.h>
using namespace std;

int num_different_bits(int x, int y){
    int diff = 0;
    for(int i = 0; i < 32; i++){
        if(x&(1<<i) != y&(1<<i)) diff++;
    }
    return diff;
}

int main(){
    int tt;
    cin>>tt;
    while(tt--){
        int a, b;
        cin>>a>>b;
        int val = 0;
        for(int i = 0; i < a; i++){
            val ^= i;
        }
        bool is_a_solution ;
        int ans = a + num_different_bits(val, b) + (is_a_solution);
        cout<<ans<<endl;
    }
    return 0;
}
