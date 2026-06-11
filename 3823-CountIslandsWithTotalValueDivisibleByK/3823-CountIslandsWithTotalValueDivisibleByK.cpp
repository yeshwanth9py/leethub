// Last updated: 6/11/2026, 11:15:27 AM
class Solution {
public:
    vector<vector<int>> vis;
    vector<vector<int>> mat;
    int kk;
    int n;
    int m;
    
    bool isvalid(int r, int c){
        if(r<0 || c<0 || r>=n || c>=m || vis[r][c] == 1){
            return 0;
        }
        return 1;
    }
    
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    
    int dfs(int x, int y){
        vis[x][y] = 1;
        // int curc = mat[x][y];
        cout<<x<<" "<<y<<" ";
        int summ = mat[x][y];
        for(int i=0; i<4; i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(!isvalid(nx, ny)) continue;
            if(mat[nx][ny] == 0) continue;
            summ = (summ + dfs(nx, ny))%kk;
            summ %= kk;
        }
        
        return summ; 
    }
    
    int countIslands(vector<vector<int>>& grid, int k) {
        this->kk = k;
        n = grid.size();
        m = grid[0].size();
        vis.clear();
        vis.resize(n, vector<int>(m, 0));
        this->mat = grid;

        int cnt = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(vis[i][j]==0 && mat[i][j] != 0){
                    int gets = dfs(i, j);
                    cout<<"\n";
                    if(gets%kk == 0){
                        cnt++;
                    }
                }
            }
        }

        return cnt;
        
        
    }
};