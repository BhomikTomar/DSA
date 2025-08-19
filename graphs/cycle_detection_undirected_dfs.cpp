#include <bits/stdc++.h>
using namespace std;

bool dfs(int node, int parent, vector<int> &visited, vector<vector<int>> &adj) {
    visited[node] = 1;
    for(int adjNode : adj[node]) {
        if(!visited[adjNode]) {
            dfs(adjNode, node, visited, adj);
        } else if(adjNode != parent) {
            return true; 
        }   
    }
    return false; 
}

bool isCyclic(int n, vector<vector<int>> &adj) {
    vector<int> visited(n, 0);  

    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            if(dfs(i, -1, visited, adj)) {
                return true; 
            }
        }
    }
    return false; 
}