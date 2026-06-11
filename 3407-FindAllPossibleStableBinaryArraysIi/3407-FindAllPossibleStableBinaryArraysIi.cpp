// Last updated: 6/11/2026, 11:18:26 AM
class Solution {
public:
    int n;
    int zero;
    int one;
    int lim;
    int dp[1111][1111][2];
    const int mod = 1e9+7;
    
    int rec(){
        // if(noz+noo==0){
        //     return 1;
        // }
        // int myl = lim;
        // if(prev == 0){
        //     myl = min(myl, noo);
        // }else{
        //     myl = min(myl, noz);
        // }

        // int ans = 0;
        // for(int i=1; i<=myl; i++){
        //     if(prev == 1){
        //         ans += rec(noz-i, noo, 0);
        //     }else{
        //         ans += rec(noz, noo-i, 1);
        //     }
        // }
        // return ans;
        vector<vector<int>> pref0(zero+6, vector<int>(one+6, 0));
        vector<vector<int>> pref1(zero+6, vector<int>(one+6, 0));

        for(int noz=0; noz<=zero; noz++){
            for(int noo=0; noo<=one; noo++){
                for(int prev=0; prev<=1; prev++){
                    if(noz + noo == 0){
                        dp[noz][noo][prev] = 1;
                        if(prev == 0){
                            pref0[noz][noo] = 1;
                        }else{
                            pref1[noz][noo] = 1;
                        }
                        continue;
                    }else{
                        int myl = lim;
                        if(prev == 0){
                            myl = min(myl, noo);
                        }else{
                            myl = min(myl, noz);
                        }
                        int ans = 0;
                        // for(int i=1; i<=myl; i++){
                        //     if(prev == 1){
                        //         ans += dp[noz-i][noo][0];
                        //     }else{
                        //         ans += dp[noz][noo-i][1];
                        //     }
                        // }
                        if(prev == 1){
                            ans = (noz-1>=0?pref0[noz-1][noo]:0) - (noz-myl-1>=0?pref0[noz-myl-1][noo]:0);
                        }else{
                            ans = (noo-1>=0?pref1[noz][noo-1]:0) - (noo-myl-1>=0?pref1[noz][noo-myl-1]:0);
                        }
                        ans = (ans+mod)%mod;

                        dp[noz][noo][prev] = ans;
                        if(prev == 0){
                            pref0[noz][noo] += (((noz-1>=0?pref0[noz-1][noo]:0) + ans)%mod + mod)%mod;
                        }else{
                            pref1[noz][noo] += (((noo-1>=0?pref1[noz][noo-1]:0) + ans)%mod+mod)%mod;
                        }
                    }
                }
            }
        }

        return ((dp[zero][one][0] + dp[zero][one][1])%mod + mod)%mod;
    }

    int numberOfStableArrays(int zero, int one, int limit) {
        n = zero+one;
        this->zero = zero;
        this->one = one;
        lim = limit;
        return rec();
    }
};



