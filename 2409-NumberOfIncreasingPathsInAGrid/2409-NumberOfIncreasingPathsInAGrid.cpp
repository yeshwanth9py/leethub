// Last updated: 6/11/2026, 11:22:49 AM
class Solution {
public:
    vector<vector<int>> arr;
    int dx[4] = {1, 0, 0, -1};
    int dy[4] = {0, 1, -1, 0};
    const int mod = 1e9+7;
    int n;
    int m;
    int dp[1111][1111];
    int rec(int r, int c){

        if(dp[r][c] != -1) return dp[r][c];
        int cur = arr[r][c];
        int way = 1;
        for(int i=0; i<4; i++){
            int nr = r+dx[i];
            int nc = c+dy[i];
            if(nr<0 || nc<0 || nr>=n || nc>=m) continue;
            if(arr[nr][nc]>arr[r][c]){
                way += rec(nr, nc);
                way = (way%mod + mod)%mod;
            }
        }

        return dp[r][c] = way;
    }
    int countPaths(vector<vector<int>>& grid) {
        arr = grid;
        n = arr.size();
        m = arr[0].size();
        int tot = 0;
        memset(dp, -1, sizeof(dp));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                tot += rec(i, j);
                tot = (tot%mod+mod)%mod;
            }
        }

        return tot;

    }
};