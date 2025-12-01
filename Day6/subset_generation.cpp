#include<bits/stdc++.h>
using namespace std;

void gen_subset(int n){
    // generator all subsets of {1, 2, ... n}
    for(int mask = 0; mask < 1<<n; mask++){
        cout<<"{ ";
        bool isStart = false;
        for(int bit = 0; bit < n; bit++){
            if(mask & (1<<bit)){
                if(isStart) cout<<", ";
                else isStart = true;
                cout<<bit;
            }
        }
        cout<<"}\n";
    }
}

int main(){
    int n;
    cin>>n;
    cout<<"Following are all subsets of {1, 2, ... n} :- \n"<<endl;
    gen_subset(n);
    return 0;
}
