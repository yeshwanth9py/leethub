// Last updated: 6/11/2026, 11:28:30 AM
class Solution {
public:
    int len;
    const int mod = 1e9+7;
    int dp[501][501];
    long long rec(long long idx, long long str){
        if(idx<0 || idx>=len) return 0;
        if(str == 0){
            if(idx == 0) return 1;
            return 0;
        }
        if(dp[idx][str] != -1) return dp[idx][str];
        long long w = ((rec(idx, str-1) + rec(idx-1, str-1) + rec(idx+1, str-1))%mod + mod)%mod;
        return dp[idx][str] = w;
    }

    
    int numWays(int steps, int arrLen) {
        len = arrLen;
        memset(dp, -1, sizeof(dp));
        return rec(0, steps);
    }
};



