// Last updated: 6/11/2026, 11:37:24 AM
class Solution {
public:
    int n;
    int m;
    vector<vector<int>> arr;
    long long dp[2][111];
    long long rec(){
        for(long long r = n-1; r>=0; r--){
            for(long long c=m-1; c>=0; c--){
                if(r == n-1 && c == m-1){
                    if(arr[r][c] == 0){
                        dp[r%2][c] = 1;
                    }else{
                        dp[r%2][c] = 0;
                    }
                    continue;
                }

                long long ri = 0;
                if(c+1<m && arr[r][c+1] != 1) ri += dp[r%2][c+1];
                long long dow = 0;
                if(r+1<n && arr[r+1][c] != 1) dow += dp[(r+1)%2][c];

                dp[r%2][c] = (ri+dow);
                if(arr[r][c] == 1){
                    dp[r%2][c] = 0;
                }
            }
        }

        return dp[0][0];
    }

    int uniquePathsWithObstacles(vector<vector<int>>& ob) {
        arr = ob;
        n = arr.size();
        m = arr[0].size();
        
        return rec();
    }
};