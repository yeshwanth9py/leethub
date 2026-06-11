// Last updated: 6/11/2026, 11:26:49 AM
class Solution {
public:
    long long n, m;
    long long vis[17][17];
    pair<long long, long long> dp[17][17];
    const long long mod = 1e9+7;

    vector<vector<int>> arr;
    pair<long long, long long> rec(long long r, long long c){
        if(r == n-1 && c == m-1){
            return {arr[r][c], arr[r][c]};
        }
        if(vis[r][c] != -1) return dp[r][c];
        long long cur = arr[r][c];
        long long curmx = -1e9;
        long long curmn = 1e9;
        if(c+1<m){
            auto [mxr, mir] = rec(r, c+1);
            curmx = max(cur*mxr, cur*mir);
            curmn = min(cur*mxr, cur*mir);
        }
        
        if(r+1<n){
            auto [mxd, mid] = rec(r+1, c);
            curmx = max({cur*mxd, cur*mid, curmx});
            curmn = min({cur*mxd, cur*mid, curmn});
        }

        vis[r][c] = 1;
        return dp[r][c] = {curmx, curmn};
    }

    int maxProductPath(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        memset(vis, -1, sizeof(vis));

        arr = grid;
        auto [mx, mn] = rec(0, 0);
        if(mx<0) return -1;
        mx = mx%mod;
        return mx;
    }
};