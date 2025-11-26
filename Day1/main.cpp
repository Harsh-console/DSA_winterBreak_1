#include<bits/stdc++.h>
#define ll long long
#define MX 100
using namespace std;

// doesn't store previously stored values
ll fib(ll n){
    if(n <2) return n; // return base case
    return fib(n-1) + fib(n-2);
}

//memoization
ll cache[MX];
//for(int i = 0; i < MX; ++i) cache[i] = -1;
/*
 * cache [0, 1, .. n]
 * store f(n) at cache[n] : n = 0, 1, ... ,n
 * how do we know if ith index is known!
 * method 1 : check if cache[n] = -1; but first set all elements of cache as 1
 */

ll cfib(ll n){
    if(cache[n] != 0) return cache[n];
    if(n < 2) {
        return cache[n] = n;
    }
    return cache[n] = cfib(n-1) + cfib(n-2);
}

// iterative dp
void pullFib(int n){
    ll fib[MX] = {0, 1};
    for(int i = 0; i < n; ++i){
        fib[i] = fib[i - 1] + fib[i - 2];
    }
}

ll pushFib(int n){
    ll f[MX] = {0, 1};
    for(int i = 0; i < n ; i++){
        f[i+1] += f[i];
        f[i+2] += f[i];
    }
    return f[n];
}

void reallySimpleSort(int arr[], int n){
    // if arr consists of only 1 and 2, then count the number of 1's and 2's in the array
    int k = 0;
    for(int i = 0; i < n; ++i) if(arr[i] == 1) k++;
    for(int i = 0; i < n; ++i){
        if( i < n) arr[i] = 1;
        else arr[i] = 2;
    }
    //time complexity = O(n)
}

/*
 * warning : syntax and logical errors!
void GeneralizedReallySimpleSort(int arr[], int n, int m){
    int equal[m] ; // equal[k] denotes number of times k occured in arr
    // given that numbers in arr are in range [0, m-1]
    for(int i = 0; i < n; ++i) equal[arr[i]]++;
    int less[m] = {0};
    for(int i = 1; i < m; i++){
        less[i] = less[i-1] + equal[i];
    }
    int B[n];
    int next[m];
    for(int i - 0; i < m; i++) next[j] = less[j] + 1;
    for(int i = 0; i < n; i++){
        int key = arr[i];
        int index = next[key];
        B[index] = key;
        next[key]++;
    }
    for(int i = 0; i < n; i++) arr[i] = B[i];
}
*/
void GeneralizedReallySimpleSort(int a[], int n, int m){
    // array a contains integers in interval [0, m)
    int equal[m] = {0};
    for(int i = 0; i < n; i++) equal[a[i]]++;
    int index = 0;
    int going = equal[0];
    for(int i = 0; i < n; i++){
        if(going == 0) going = equal[++index];
        a[i] = index;
        going--;
    }
    // time complexity = o(n + n) = o(n)
    // space comlexity = o(m)
}

void printArray(int arr[], int n){
    for(int i = 0; i < n; i++) cout<<arr[i]<<endl;
}
int main(){
    /*
    memset(cache, -1, sizeof(cache));
    int n;
    cout<<"Please Enter the Number : "; cin>>n;
    cout<<"Fib("<<n<<") = "<<pushFib(n)<<".";
    */
    int arr[] = {4, 3, 1, 2, 0};
    GeneralizedReallySimpleSort(arr, 5, 5);
    printArray(arr, 5);
    return 0;
}
