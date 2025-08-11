#include <bits/stdc++.h>
using namespace std;
vector<int> bfs(int V, int E, vector<vector<int>>& adj){
    vector<int> ans;
    vector<int> visited(V, 0);
    queue<int> q;
    q.push(0);
    visited[0] = 1;

    while(!q.empty()){
        int el = q.front();
        q.pop();
        ans.push_back(el);

        for(auto it : adj[el]){
            if(!visited[it]){
                visited[it] = 1;
                q.push(it);
            }
        }
    }
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

        vector<int> ans = bfs(V, E, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
    }
    return 0;
}