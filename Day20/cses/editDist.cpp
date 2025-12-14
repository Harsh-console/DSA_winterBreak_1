#include<bits/stdc++.h>
using namespace std;

int lev(string& a, string& b){
    if(!b.size()) return a.size();
    if(!a.size()) return b.size();
    string a_tail = a; a_tail.erase(0, 1);
    string b_tail = b; b_tail.erase(0, 1);
    if(a[0] == b[0]) return lev(a_tail, b_tail);
    return 1 + min(min(lev(a_tail, b), lev(a, b_tail)), lev(a_tail, b_tail));
}

int main(){
    string a;
    string b;
    cin>>a>>b;
    cout<<lev(a, b)<<endl;
    return 0;
}
