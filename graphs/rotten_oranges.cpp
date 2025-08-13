#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int,int>> q;
        int fresh = 0;

        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (grid[i][j] == 2)       q.push({i, j});
                else if (grid[i][j] == 1)  ++fresh;

        if (fresh == 0) return 0;   
        if (q.empty())  return -1;  

        const pair<int,int> dirs[4] = {{1,0},{0,1},{-1,0},{0,-1}};
        int minutes = -1;           

        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                auto [r, c] = q.front(); q.pop();

                for (auto [dr, dc] : dirs) {
                    int nr = r + dr, nc = c + dc;
                    if (nr >= 0 && nr < m && nc >= 0 && nc < n &&
                        grid[nr][nc] == 1)                 
                    {
                        grid[nr][nc] = 2;                  
                        --fresh;
                        q.push({nr, nc});
                    }
                }
            }
            ++minutes;         
        }

        return fresh == 0 ? minutes : -1;
    }
};
