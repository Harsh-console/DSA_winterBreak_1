#include<bits/stdc++.h>
using namespace std;

int main(){
    int tt;
    cin>>tt;
    while(tt--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i = 0; i < n; i++) cin>>a[i];
        //him[i] = the smallest number of skip points req. to kill bosses [i .. n) if it's our friends turn to move
        //us[i] = the smallest number of skip points req. to kill bosses i...n if it's our turn to move
        vector<int> him(n+1);
        vector<int> us(n+1);
        him[n] = us[n] = 0; 
        for(int i = n - 1; i >= 0; i--){
            {
                // calculate him[i]
                him[i] = us[i+1] + a[i];
                if(i+2 <= n){
                    him[i] = min(him[i], us[i+2] + a[i] + a[i+1]);
                }
            }
            {
                // calculate us[i]
                us[i] = him[i+1];
                if(i + 2 <= n){
                    us[i] = min(him[i+1], him[i+2]);
                }
            }
        }
        cout<<him[0]<<endl;
    }
}
