// Last updated: 6/11/2026, 11:18:27 AM
class Solution {
public:
    int zero;
    int one;
    int lim;
    const int mod = 1e9+7;
    int dp[211][211][2];
    int rec(int oneleft, int zerleft, int prevu){
        if(oneleft<0 || zerleft<0) return 0;
        if(oneleft + zerleft == 0){
            return 1;
        }
        if(dp[oneleft][zerleft][prevu] != -1) return dp[oneleft][zerleft][prevu];
        int ans = 0;
        if(prevu == 1){
            for(int len=1; len<=min(lim, zerleft); len++){
                ans += rec(oneleft, zerleft-len, 0)%mod;
                ans = (ans%mod + mod)%mod;
            }
        }else{
            for(int len=1; len<=min(lim, oneleft); len++){
                ans += rec(oneleft-len, zerleft, 1)%mod;
                ans = (ans%mod + mod)%mod;
            }
        }

        return dp[oneleft][zerleft][prevu] = ans;
    }

    int numberOfStableArrays(int zero, int one, int limit) {
        this->zero = zero;
        this->one = one;
        lim = limit;
        memset(dp, -1, sizeof(dp));
        return ((rec(one, zero, 0) + rec(one, zero, 1))%mod + mod)%mod;
    }
};