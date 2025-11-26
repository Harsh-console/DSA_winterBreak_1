#include<bits/stdc++.h>
#define INF 1000000
using namespace std;

void find_maximum_crossing_subarray(int arr[], int low, int mid, int high, int ans[]){
    // ans[]={max_left, max_right, left_sum + right_sum}
    int left_sum = 0;
    for(int i = low; i <= mid; i++) left_sum += arr[i];
    int max_left_sum = - INF;
    int max_left = low;
    for(int i = low; i < mid; i++) {
        left_sum -= arr[i];
        if(left_sum > max_left_sum){
            max_left_sum = left_sum;
            max_left = i;
        }
    }
    int right_sum = 0;
    for(int i = mid; i <= high; i++) right_sum += arr[i];
    int max_right_sum = -INF;
    int max_right = high;
    for(int i = high; i > mid; i--){
        right_sum -= arr[i];
        if(right_sum > max_right_sum){
        max_right_sum = right_sum;
        max_right = i;
        }
    }
    ans[0] = max_left; ans[1] = max_right; ans[2] = max_left_sum + max_right_sum;
    return;
}

void find_maximum_subarray(int arr[], int low, int high, int ans[]){
    // ans[] = {start, end, sum}
    // base case occurs when there is only one element
    if(low >= high){
        ans[0] = low; ans[1] = high; ans[2] = arr[low];
        return;
    }
    int ans_left[3] = {0};
    int ans_right[3] = {0};
    int ans_crossed[3] = {0};
    int mid = (low + high) / 2;
    find_maximum_subarray(arr, low, mid, ans_left);
    find_maximum_subarray(arr, mid+1, high, ans_right);
    find_maximum_crossing_subarray(arr, low, mid, high, ans_crossed);
    /* warning : there might be syntax error here!
    int* sum_array[3] = {ans_left, ans_right, ans_crossed};
    int max_index = 0;
    if(ans_right[2] > ans_left[2]) max_index = 1;
    if(ans_crossed[2] > sum_array[max_index][2]) max_index = 2;
    ans[0] = sum_array[max_index][0]; ans[1] = sum_array[max_index][1]; ans[2] = sum_array[max_index][2];
    */
    if(ans_left[2] >= ans_right[2] && ans_left[2] >= ans_crossed[2]){
        ans[0] = ans_left[0]; ans[1] = ans_left[1]; ans[2] = ans_left[2];
        return;
    }
    if(ans_right[2] >= ans_left[2] && ans_right[2] >= ans_crossed[2]){
        ans[0] = ans_right[0]; ans[1] = ans_right[1]; ans[2] = ans_right[2];
        return;
    }
    ans[0] = ans_crossed[0]; ans[1] = ans_crossed[1]; ans[2] = ans_crossed[2];
    return;
}

int main(){
    cout<<"Let's Go!"<<endl;
    //int arr[5] = {0, 1 ,-4, 3, -4};
    int ans[3] = {0};
    int arr[] = {
        -5, 2, 3, -2, 4, -1, 2, -3, 6, -5,
         4, 3, -2, 1, -4, 6, 2, -1, 3, -2,
         5, -3, 4, -1, 2, -4, 3, -2, 1, 4
    };
    int n = 30;

    find_maximum_subarray(arr, 0, n - 1, ans);
    cout<<"Maximum subarray is :\nlow = "<<ans[0]<<"\nhigh = "<<ans[1]<<"\nsum = "<<ans[2]<<endl;
    return 0;
}
