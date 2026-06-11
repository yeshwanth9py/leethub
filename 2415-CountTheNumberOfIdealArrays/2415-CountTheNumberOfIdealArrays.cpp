// Last updated: 6/11/2026, 11:22:47 AM
class Solution {
public:
    int mod = 1e9+7;
    int maxValue;
    long long dp1[10010][16];
    long long dp2[10011][16];
    long long rec(int st, int len){
        if(len == 1){
            return 1;
        }
        if(dp1[st][len]!=-1){
            return dp1[st][len];
        }
        long long ways = 0;
        for(int nv=2*st; nv<=maxValue; nv+=st){
            ways += rec(nv, len-1)%mod;
            ways %= mod;
        }
        return dp1[st][len] = ways;
    }

    void precompute(){
        for(int i=0; i<=10001; i++){
            for(int j=0; j<=15; j++){
                if (j == 0 || j == i) {
                    dp2[i][j] = 1;
                }
                else if (j > i) {
                    dp2[i][j] = 0;
                }
                else {
                    dp2[i][j] = (dp2[i-1][j-1] + dp2[i-1][j]) % mod;
                }
            }
        }
    }

    long long ncr(int n, int r){
        return dp2[n][r]%mod;
    }

    int idealArrays(int n, int maxValue) {
        precompute();
        memset(dp1, -1, sizeof(dp1));
        // memset(dp2, 0, sizeof(dp2));
        this->maxValue = maxValue;
        long long tot = 0;
        for(int st=1; st<=maxValue; st++){
            for(int len = 1; len<=14 && len<=n; len++){
                long long ways = rec(st, len)%mod;
                tot += (ways%mod*ncr(n-1, len-1)%mod)%mod;
                tot%=mod;
            }
        }
        return tot;


    }
};