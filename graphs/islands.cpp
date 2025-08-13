#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void bfs(int row, int col, const vector<vector<int>>& grid, vector<vector<int>>& vis) {
        int V = grid.size();
        queue<pair<int, int>> q;
        q.push({row, col});
        vis[row][col] = 1;

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (int dr = -1; dr <= 1; ++dr) {
                for (int dc = -1; dc <= 1; ++dc) {
                    int nr = r + dr, nc = c + dc;
                    if (nr >= 0 && nr < V && nc >= 0 && nc < V && !vis[nr][nc] && grid[nr][nc]) {
                        vis[nr][nc] = 1;
                        q.push({nr, nc});
                    }
                }
            }
        }
    }

    int findNumberOfComponent(int V, vector<vector<int>>& edges) {
        vector<vector<int>> grid(V, vector<int>(V, 0));
        for (size_t i = 0; i < edges.size(); ++i) {
            int r = edges[i][0], c = edges[i][1];
            grid[r][c] = 1;
        }

        vector<vector<int>> vis(V, vector<int>(V, 0));
        int cnt = 0;

        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                if (grid[i][j] && !vis[i][j]) {
                    ++cnt;
                    bfs(i, j, grid, vis);
                }
            }
        }
        return cnt;
    }
};