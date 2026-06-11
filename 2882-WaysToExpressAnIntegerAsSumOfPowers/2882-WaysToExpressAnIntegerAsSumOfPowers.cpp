// Last updated: 6/11/2026, 11:20:41 AM
class Solution {
public:
    long long nn;
    long long xx;
    long long dp[301][301];
    const long long mod = 1e9+7;
    long long rec(long long ind, long long num){
        if(num>nn) return 0;
        if(num == nn) return 1;
        if(ind > nn){
            return 0;
        }
        if(dp[ind][num]!=-1) return dp[ind][num];

        long long ways = rec(ind+1, num);
        ways += rec(ind+1, num+(pow(ind, xx)))%mod;
        ways %= mod;

        return dp[ind][num] = ways;
    }

    int numberOfWays(int n, int x) {
        this->nn = n;
        this->xx = x;
        memset(dp, -1, sizeof(dp));
        return rec(1, 0);
    }
};