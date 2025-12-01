#include<bits/stdc++.h>
using namespace std;


void dfsRecursive(int node, vector<vector<int>> &adj, vector<int> &visited){
    visited[node] = 1;
    for(int x : adj[node]){
        if(!visited[x]){
            dfsRecursive(x, adj, visited);
        }
    }
}

void dfsIterative(int start, vector<vector<int>> &adj){
    int n = adj.size();
    vector<int> visited(n, 0);
    stack<int> st;

    // initialization
    visited[start] = 1;
    st.push(start);
    while(!st.empty()){
        int node = st.top();
        st.pop();

        cout<<node<<" "; // process the node

        for(int x : adj[node]){
            if(!visited[x]){
                st.push(x);
            }
        }
    }
    cout<<"Iterative DFS completed!"<<endl;
}

int main(){
    vector<vector<int>> adj = {{1}, {2}, {3}, {4}, {5}, {0}};
    dfsIterative(0, adj);
    return 0;
}
