// Last updated: 6/11/2026, 11:27:01 AM
class Solution {
public:
    int vis[501][501];
    int n;
    int m;
    vector<vector<char>> arr;
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    bool dfs(int r, int c, int pr, int pc){
        vis[r][c] = 1;

        for(int i=0; i<4; i++){
            int nr = r+dx[i];
            int nc = c+dy[i];
            if(nr == pr && nc == pc) continue;
            if(nr>=0 && nc>=0 && nr<n && nc<m && arr[nr][nc] == arr[r][c]){
                if(vis[nr][nc] == 2) continue;
                if(vis[nr][nc] == 1){
                    return 1;
                }
                if(dfs(nr, nc, r, c)){
                    return 1;
                }
            }
        }

        vis[r][c] = 2;

        return 0;
    }

    bool containsCycle(vector<vector<char>>& grid) {
        arr = grid;
        n = arr.size();
        m = arr[0].size();
        memset(vis, 0, sizeof(vis));

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(vis[i][j] != 0) continue;
                if(dfs(i, j, -1, -1)) return 1;
            }
        }

        return 0;

    }
};