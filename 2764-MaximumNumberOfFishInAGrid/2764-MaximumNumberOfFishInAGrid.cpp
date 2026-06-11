// Last updated: 6/11/2026, 11:20:58 AM
class Solution {
public:
    int dx[4] = {1, 0, 0, -1};
    int dy[4] = {0, 1, -1, 0};
    int dfs(int x, int y, vector<vector<int>>& grid, vector<vector<int>> &vis){
        vis[x][y] = 1;
        int totf = grid[x][y];
        for(int i=0; i<4; i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(nx>=0 && ny>=0 && nx<grid.size() && ny<grid[0].size() && vis[nx][ny]==0 && grid[nx][ny]>0){
                totf += dfs(nx, ny, grid, vis);
            }
        }
        return totf;
    }

    int findMaxFish(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int maxf = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(vis[i][j]==0 && grid[i][j]>0){
                    maxf = max(maxf, dfs(i, j, grid, vis));
                }
            }
        }

        return maxf;
    }
};