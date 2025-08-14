#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<int>>& image, vector<vector<int>>& ans, int sr, int sc, int color, int start, int dr[], int dc[]){
        ans[sr][sc] = color;
        int m = image.size();
        int n = image[0].size();

        for(int i = 0; i < 4; i++){
            int nr = sr + dr[i];
            int nc = sc + dc[i];
            if(nr >= 0 && nc >= 0 && nr < m && nc < n && (image[nr][nc] == start) && (ans[nr][nc] != color)){
                    dfs(image, ans, nr, nc, color, start, dr, dc);    
                }
            }
        }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int start = image[sr][sc];
        vector<vector<int>> ans = image;

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        dfs(image, ans, sr, sc, color, start, dr, dc);
        return ans;
    }
};