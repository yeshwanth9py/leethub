// Last updated: 6/11/2026, 11:13:11 AM
class Solution {
public:
    int n;
    int m;
    vector<vector<int>> mat;
    int dp[151][151];
    int mod = 1e9+7;
    int rec(int r, int gcd){
        if(r == n){
            if(gcd == 1) return 1;
            return 0;
        }
        if(dp[r][gcd]!=-1) return dp[r][gcd];

        int copygcd = gcd;
        int ways = 0;
        for(int c=0; c<m; c++){
            copygcd = __gcd(mat[r][c], gcd);
            ways += rec(r+1, copygcd)%mod;
            ways %= mod;
        }

        return dp[r][gcd] = ways;
    }
    
    int countCoprime(vector<vector<int>>& matri) {
        mat = matri;
        n = mat.size();
        m = mat[0].size();
        memset(dp, -1, sizeof(dp));

        int ways = 0;
        for(int i=0; i<m; i++){
            ways += rec(1, mat[0][i])%mod;
            ways %= mod;
        }

        return ways;
        
    }
};