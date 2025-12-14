#include<bits/stdc++.h>
using namespace std;

string mgp(vector<vector<int>>& grid){
    // returns minimal lexologically word from 0, 0 to n-1, n-1
    int n = grid.size();
    // we want to break this into small problems
    // we want the path, now at each point, there are two options at each point, total we move n time right and n times down
    // so 2nCn ways total= TLE
    // we only consider those path which are good, being good at earliest is very important
    // so, we start at 0, 0 and suppose at some time we are at i, j, then we need to check grd[i+1][j] and grid[i][j+1] we are not out of bound, and if one of them is outof bound, then we have to choose the other one for the rest  of the path
    // we are only worried , if both the value for down and right are equal.
    // so we maintain our main path. this is like diskastra minimum cost path, but here order matters so its different.
    // but we can our store the parent of cell (i, j) as like 0 or 1 where 0 means left and 1 means up
    // if there is draw at any point we want to check which path is shorter, so 
    // we can maintain another dp where each cell shows its parent and we can backtrack, but it won't work here as order matter
    // so direction at i, j depends on path forward. we we and moving forward, we cannot move back.
    // we could make a dp where dp[i][j] = string or path(which can be given be 0 or 1) from i, j to n-1, n-1
    // dp[n-1][n-1] is null. and dp[n-1][j] and dp[i][n-1] is just straight path as we are only allowed to move right or down
    // to find dp[i][j], at the cell we have two options right or down, so just take minimum for dp[i+1][j] and dp[i][j+1] for which we could use str cmp
    // now but there is one thing to note that if n = 3000, then grid -> 3000*3000 so just reading grid will take too much time.
    // also array size has limitation, it might overflow, and also, for finding dp[i][j] we need dp[i+1][j] and dp[i][j+1] only if grid[i+1][j] == grid[i][j+1], if they are not equal we don't need them.

}

