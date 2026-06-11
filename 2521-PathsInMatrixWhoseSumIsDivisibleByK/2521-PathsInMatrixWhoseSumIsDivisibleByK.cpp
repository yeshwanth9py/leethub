// Last updated: 6/11/2026, 11:22:06 AM
class Solution {
public:
    int n;
    int m;
    vector<vector<int>> arr;
    int k;
    int mod = 1e9+7;
    vector<vector<vector<int>>> dp;
    int rec(int r, int c, int sum){
        if(r>=n || c>=m) return 0;

        if(r == n-1 && c == m-1){
            return ((sum+arr[r][c])%k == 0);
        }

        if(dp[r][c][sum]!=-1) return dp[r][c][sum];
        int cur = arr[r][c];
        // cout<<(sum+cur)<<" "<<k<<endl;
        int ri = rec(r, c+1, (sum+cur)%k);
        int dow = rec(r+1, c, (sum+cur)%k);

        return dp[r][c][sum] = (ri + dow)%mod;
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        n = grid.size();
        m = grid[0].size();
        arr = grid;
        this->k = k;
        dp.resize(n+1, vector<vector<int>>(m+1, vector<int>(k+1, -1)));

        return rec(0, 0, 0);
    }
};