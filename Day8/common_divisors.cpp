#include<bits/stdc++.h>
using namespace std;

// utkarsh singh = 𓅱 𓏏 𓎡 𓄿 𓂋 𓈙 𓋴 𓈖 𓎼( in egyptian language )
int gcd(int a, int b){
    if(!b) return a;
    return gcd(b, a%b);
}

int main(){
    int n;
    cin>>n;
    int nums[n];
    for(int i = 0; i < n; i++) cin>>nums[i];
    int max_gcd = 1;
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            if(i!=j) max_gcd = max(max_gcd, gcd(nums[i], nums[j]));
        }
    }
    cout<<max_gcd<<endl;
    return 0;
}
