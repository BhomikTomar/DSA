

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<int>>& grid, vector<vector<int>>& vis, int row, int col, int dr[], int dc[]){
        vis[row][col] = 1;
        int m = grid.size();
        int n = grid[0].size();

        for(int i = 0; i < 4; i++){
            int nr = row + dr[i];
            int nc = col + dc[i];

            if(nr < m && nc < n && nr >=0 && nc >=0 && vis[nr][nc] == 0 && grid[nr][nc] == 1){
                dfs(grid, vis, nr, nc, dr, dc);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int count = 0;
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> vis(m, vector<int>(n, 0));
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        for(int i = 0; i < m; i++){
            if(grid[i][0] == 1 && vis[i][0] == 0){
                dfs(grid, vis, i, 0, dr, dc);
            }
            if(grid[i][n - 1] == 1 && vis[i][n - 1] == 0){
                dfs(grid, vis, i, n - 1, dr, dc);
            }
        }

        for(int i = 0; i < n; i++){
            if(grid[0][i] == 1 && vis[0][i] == 0){
                dfs(grid, vis, 0, i, dr, dc);
            }
            if(grid[m - 1][i] == 1 && vis[m - 1][i] == 0){
                dfs(grid, vis, m - 1, i, dr, dc);
            }
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(vis[i][j] == 0 && grid[i][j] == 1) count++;
            }
        }

        return count;
    }
};