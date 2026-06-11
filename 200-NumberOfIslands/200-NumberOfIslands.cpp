// Last updated: 6/11/2026, 11:35:04 AM
class Solution {
public:
    int m;
    int n;
    vector<vector<int>> vis;
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    int numIslands(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();
        vis.resize(n, vector<int>(m, 0));

        function<void(int,int)> dfs = [&](int r, int c){
            if(r<0 || c<0 || r>=n || c>=m || vis[r][c] == 1 || grid[r][c] == '0') return;
            vis[r][c] = 1;
            for(int i=0; i<4; i++){
                int nr = r+dx[i];
                int nc = c+dy[i];
                dfs(nr, nc);
            }
        };

        int noi = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == '1' && vis[i][j] == 0){
                    dfs(i, j);
                    noi++;
                }
            }
        }

        return noi;
    }
};