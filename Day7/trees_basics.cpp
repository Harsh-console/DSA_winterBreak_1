#include<bits/stdc++.h>
using namespace std;

bool isTree(vector<pair<int, int>> &Edges){
    bool is_tree;
    
}

int main(){
    // let nodes be integers 1, 2, 3, ... n.
    int m; //m = number of edges in given graph
    // each edge is pair of nodes
    vector<pair<int, int>> Edges(m);
    for(pair<int, int> edge : Edges) cin>>edge.first>>edge.second;
    bool is_tree = isTree(Edges);
}
