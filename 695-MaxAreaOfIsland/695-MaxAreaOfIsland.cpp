// Last updated: 6/11/2026, 11:31:53 AM
class Solution {
public:
    int dx[4] = {1, 0, 0,-1};
    int dy[4] = {0, 1, -1, 0};
    bool isvalid(int x, int y, int n, int m){
        return x>=0 && y>=0 && x<n && y<m;
    }
    int dfs(int x, int y, vector<vector<int>> &vis, vector<vector<int>> &grid){
        vis[x][y] = 1;
        int sz = 1;
        for(int i=0; i<4; i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(isvalid(nx, ny, grid.size(), grid[0].size()) && vis[nx][ny] == 0 && grid[nx][ny] == 1){
                sz += dfs(nx, ny, vis, grid);
            }
        }
        return sz;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int maxarea = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(vis[i][j] == 0 && grid[i][j] == 1){
                    maxarea = max(maxarea, dfs(i, j, vis, grid));
                }
            }
        }

        return maxarea;

    }
};