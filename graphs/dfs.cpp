#include <bits/stdc++.h>
using namespace std;
void helper(int node, vector<int>& ans, vector<vector<int>>& adj, vector<int>& vis){
    vis[node] =1;
    ans.push_back(node);

    for(auto it: adj[node]){
        if(!vis[it]){
            helper(it, ans, adj, vis);
        }
    }
}

vector<int> dfs(int V, int E, vector<vector<int>>& adj){
    vector<int> ans;
    vector<int> vis(V, 0);

    helper(0, ans, adj, vis);
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int V; cin >> V;
        int E; cin >> E;
        vector<vector<int>> adj(V);
        
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u); 
        }

        vector<int> ans = dfs(V, E, adj);

        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
    }
    return 0;
}