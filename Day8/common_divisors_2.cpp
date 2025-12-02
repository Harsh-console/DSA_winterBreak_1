#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int INF = 1e9+7;
    vector<int> arr(n);
    int best = -INF;
    for(int i = 0; i < n; i++){
        cin>>arr[i];
        if(arr[i] > best) best = arr[i];
    }
    while(best){
        int cnt = 0;
        for(int x : arr) {
            if(!(x%best)) cnt++;
            if(cnt > 1) break;
        }
        if(cnt > 1) break;
        best--;
    }
    cout<<best<<endl;
    return 0;
}
