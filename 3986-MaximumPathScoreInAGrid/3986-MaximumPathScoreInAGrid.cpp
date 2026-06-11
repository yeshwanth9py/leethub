// Last updated: 6/11/2026, 11:14:09 AM
class Solution {
public:
    int n, m;
    int k;
    int dp[211][211][211];
    vector<vector<int>> arr;
    int rec(int r, int c, int cost){
        if(cost>k || r>=n || c>=m || r<0 || c<0) return -1e9;
        if(r == n-1 && c == m-1){
            if(arr[r][c] == 0){
                return 0;
            }
            if(arr[r][c] == 1){
                if(cost == k) return -1e9;
                return 1;
            }
            if(cost == k) return -1e9;
            return 2;
        }

        if(dp[r][c][cost] != -1) return dp[r][c][cost];

        int ans = -1e9;
        int curcost = arr[r][c];

        int adder = cost + ((arr[r][c]>0)?1:0);
        ans = max(ans, curcost + rec(r+1, c, adder));
        ans = max(ans, curcost + rec(r, c+1, adder));

        return dp[r][c][cost] = ans;
    }

    int maxPathScore(vector<vector<int>>& arr, int k) {
        n = arr.size();
        m = arr[0].size();
        this->k = k;
        this->arr = arr;

        memset(dp, -1, sizeof(dp));

        int ans = rec(0, 0, 0);
        if(ans<0) return -1;
        return ans; 
    }
};