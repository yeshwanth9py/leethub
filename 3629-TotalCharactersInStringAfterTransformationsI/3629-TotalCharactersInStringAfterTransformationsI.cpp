// Last updated: 6/11/2026, 11:17:20 AM
class Solution {
public:
    int mod = 1e9+7;
    int dp[28][100001];
    int rec(int ind, int t){
        if(t == 0){
            return 1;
        }
        if(dp[ind][t]!=-1){
            return dp[ind][t];
        }
        if(ind == 25){
            return dp[ind][t] = (rec(0, t-1)%mod+rec(1, t-1)%mod)%mod;
        }else{
            return dp[ind][t] = rec(ind+1, t-1)%mod;
        }
    }

    int lengthAfterTransformations(string s, int t) {
        int sz = 0;
        memset(dp, -1, sizeof(dp));
        for(int i=0; i<s.length(); i++){
            sz += rec(s[i]-'a', t)%mod;
            sz %= mod;
        }
        return sz;
    }
};