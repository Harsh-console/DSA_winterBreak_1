#include<bits/stdc++.h>
using namespace std;
int max_gcd(int arr[], int n){
    int mx = 0;
    for(int i = 0; i < n; i++) mx = max(mx, arr[i]);
    vector<int> freq(mx+1, 0);
    for(int i = 0; i < n; i++) freq[arr[i]]++;
    int g = mx;
    while(g >= 1){
        int cnt = 0;
        for(int multiple = g; multiple <= mx; multiple += g){
            cnt += freq[multiple];
            if(cnt>1) return g;
        }
        g--;
    }
    
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i < n; i++) cin>>arr[i];
    cout<<max_gcd(arr, n)<<endl;
}
