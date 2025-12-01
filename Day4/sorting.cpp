#include<bits/stdc++.h>
using namespace std;

void swap(int arr[], int i, int j){
    arr[i] ^= arr[j];
    arr[j] ^= arr[i];
    arr[i] ^= arr[j];
}

void bubblesort(int arr[], int n){
    // after k rounds of 1st loop, k largest elements will be in correct position
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(arr[j] > arr[j+1]){
                swap(arr, j , j+1);
            }
        }
    }
}

void merge(int arr[], int low, int mid, int high){
    int a = low; 
    int b = mid + 1;
    int n = high - low + 1;
    int newArr[n];
    int k = 0;
    while(a <= mid && b <= high){
        bool Bool = ( arr[a] > arr[b] );
        if(Bool) newArr[k++] = arr[a++];
        else newArr[k++] = arr[b++];
    }
    while(a <= mid) newArr[k++] = arr[a++];
    while(b <= high) newArr[k++] = arr[b++];
    for(int i = low; i <= high; i++){
        arr[i] = newArr[i - low];
    }
}

void mergeSort(int arr[], int low, int high){
    if(low>= high) return;
    int mid = (low + high) / 2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid+1, high);
    merge(arr, low, mid, high);
}

void countingSort(int arr[], int n, int m){
    // arr contain elements in range [0, m)
    int equal[m] = {0};
    for(int i = 0; i < n; i++) equal[arr[i]]++;
    int going = equal[0];
    int index = 0;
    for(int i = 0; i < n; i++){
        while(!going) going+= equal[++index];
        arr[i] = index;
        going--;
    }
}

void printArr(int arr[], int n){
    for(int i = 0; i < n; i++) cout<<arr[i]<<endl;
}

int main(){
    int arr[] = {5, 3, 6, 2, 8, 1, 1, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    //countingSort(arr, n, 9);
    sort(arr, arr + n);
    printArr(arr, n);
    /*
    vector<int> v = {4, 2, 5, 3, 5, 8, 3};
    sort(v.begin(), v.end());
    sort(v.rbegin(), v.rend());

    int a[] = {4, 2, 5, 3, 5, 8, 3};
    int n = sizeof(a) / sizeof(a[0]);
    sort(a, a + n);
    string s = "monkey";
    sort(s.begin(), s.end());
    cout<<s<<endl;
    */
}
