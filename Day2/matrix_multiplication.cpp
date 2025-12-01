#include<bits/stdc++.h>
#define MX 100
using namespace std;

void matrixMultiplication_using_bruteForce(int a[MX][MX], int b[MX][MX], int p, int q, int r, int c[MX][MX]){
    for(int i = 0; i < p; i++){
        for(int j = 0; j < r; j++){
            c[i][j] = 0;
            for(int k = 0; k < q; k++) c[i][j] += a[i][k] * b[k][j];
        }
    }
}

void printMatrix(int arr[MX][MX], int p, int q){
    for(int i = 0; i < p; i++){
        for(int j = 0; j < q; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(void){
    int p = 3, q = 3, r = 3;
    int a[MX][MX] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int b[MX][MX] = {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}
    };

    int c[MX][MX] = {0};
    matrixMultiplication_using_bruteForce(a, b, p, q, r, c);
    printMatrix(c, p, r);
    return 0;
}
