#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<char>>& board, vector<vector<int>>& vis, int row, int col, int dr[], int dc[]) {
        vis[row][col] = 1;
        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < 4; i++) {
            int nr = row + dr[i];
            int nc = col + dc[i];

            if (nr >= 0 && nc >= 0 && nr < m && nc < n 
                && vis[nr][nc] == 0 && board[nr][nc] == 'O') {
                dfs(board, vis, nr, nc, dr, dc);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int m = board.size();
        if (m == 0) return;
        int n = board[0].size();

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        vector<vector<int>> vis(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O' && vis[i][0] == 0)
                dfs(board, vis, i, 0, dr, dc);
            if (board[i][n - 1] == 'O' && vis[i][n - 1] == 0)
                dfs(board, vis, i, n - 1, dr, dc);
        }
        for (int j = 0; j < n; j++) {
            if (board[0][j] == 'O' && vis[0][j] == 0)
                dfs(board, vis, 0, j, dr, dc);
            if (board[m - 1][j] == 'O' && vis[m - 1][j] == 0)
                dfs(board, vis, m - 1, j, dr, dc);
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O' && vis[i][j] == 0)
                    board[i][j] = 'X';
            }
        }
    }
};
