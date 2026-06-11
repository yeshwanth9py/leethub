// Last updated: 6/11/2026, 11:35:24 AM
class Solution {
public:
    int n;
    int m;
    vector<vector<int>> arr;
    int dp[201][201];
    int rec(int r, int c){
        //pruning
        if(r>=n || c>=m){
            return 1e9;
        }
        //base case
        if(r == n-1 && c == m-1){
            int curminh = 1-arr[r][c];
            if(curminh<=0){
                curminh = 1;
            }
            return curminh;
        }

        if(dp[r][c]!=-1){
            return dp[r][c];
        }

        int rightm = rec(r, c+1);
        int bottom = rec(r+1, c);
        int curminh = min(rightm, bottom) - arr[r][c];

        if(curminh<=0){
            curminh = 1;
        }
        return dp[r][c] = curminh;
    }

    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        arr = dungeon;
        n = dungeon.size();
        m = dungeon[0].size();
        memset(dp, -1, sizeof(dp));
        return rec(0, 0);
    }
};