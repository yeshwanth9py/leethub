// Last updated: 6/11/2026, 11:32:45 AM
class Solution {
public:
    int n;
    int dp[(1LL<<17)];
    int rec(int ind, int mask){
        if(ind == n){
            return 1;
        }
        if(dp[mask]!=-1) return dp[mask];
        int ways = 0;
        for(int i=0; i<n; i++){
            if((mask & (1LL<<i)) == 0){
                int pi = i+1;
                int ci = ind+1;
                if(pi%ci == 0 || ci%pi == 0){
                    ways += rec(ind+1, (mask|(1LL<<i)));
                }
            }
        }

        return dp[mask] = ways;
    }
    int countArrangement(int n) {
        this->n = n;
        memset(dp, -1, sizeof(dp));
        return rec(0, 0);
    }
};