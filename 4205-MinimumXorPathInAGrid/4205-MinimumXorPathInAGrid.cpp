// Last updated: 6/11/2026, 11:10:39 AM
class Solution {
public:
    vector<vector<int>> arr;
    int n;
    int m;
    vector<vector<vector<int>>> dp;
    int rec(int r, int c, int xr){
        if(r == n-1 && c == m-1){
            return xr^arr[r][c];
        }
        if(dp[r][c][xr] != -1) return dp[r][c][xr];
        int ans = 1e9;
        if(c+1<m){
            ans = min(ans, rec(r, c+1, xr^arr[r][c]));
        }
        if(r+1<n){
            ans = min(ans, rec(r+1, c, xr^arr[r][c]));
        }
        return dp[r][c][xr] = ans;
    }
    
    int minCost(vector<vector<int>>& arrr) {
        arr = arrr;
        n = arr.size();
        m = arr[0].size();
        dp.resize(n, vector<vector<int>>(m, vector<int>(1111, -1)));
        return rec(0, 0, 0);
    }
};




