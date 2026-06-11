// Last updated: 6/11/2026, 11:16:50 AM
class Solution {
public:
    int n;
    int m;
    vector<vector<int>> arr;
    int dp[501][501][3];
    int vis[501][501][3];
    int rec(int r, int c, int neurem){
        if(neurem<0 || r>=n || c>=m) return -1e9;
        if(r == n-1 && c == m-1){
            int maxr = arr[r][c];
            if(neurem>0){
                maxr = max(maxr, 0);
            }
            return maxr;
        }

        if(vis[r][c][neurem] != -1) return dp[r][c][neurem];

        int v = -1e9;
        int cur = arr[r][c];

        v = max({v, cur+rec(r+1, c, neurem), cur+rec(r, c+1, neurem)});
        if(neurem>0){
            v = max({v, rec(r+1, c, neurem-1), rec(r, c+1, neurem-1)});
        }

        vis[r][c][neurem] = 1;
        return dp[r][c][neurem] = v;
    }


    int maximumAmount(vector<vector<int>>& coins) {
        arr = coins;
        n = arr.size();
        m = arr[0].size();
        memset(vis, -1, sizeof(vis));
        return rec(0, 0, 2);
    }
};