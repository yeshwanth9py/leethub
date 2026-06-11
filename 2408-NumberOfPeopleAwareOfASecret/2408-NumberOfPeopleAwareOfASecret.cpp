// Last updated: 6/11/2026, 11:22:50 AM
class Solution {
public:
    int delay;
    int forget;
    int dp[1001];
    int mod = 1e9+7;
    int n;
    int rec(){
        // if(n==1) return 1;
        // if(dp[n]!=-1) return dp[n];
        // int cnt = 0;
        // for(int prev=n-forget+1; prev<=n-delay; prev++){
        //     if(prev<=0) continue;
        //     cnt += rec(prev)%mod;
        //     cnt %= mod;
        // }
        // return dp[n] = cnt;

        dp[1] = 1;
        int cnt = 0;
        for(int cur=1; cur<=n; cur++){
            if(cur == 1){
                // cnt = 1;
                continue;
            }
            // for(int prev=cur-forget+1; prev<=cur-delay; prev++){
            //     if(prev<=0) continue;
            //     cnt += dp[prev]%mod;
            //     cnt %= mod;
            // }
            if(cur-delay>=0){
                cnt += dp[cur-delay]%mod;
                cnt %= mod;
            }
            if(cur-forget>=0){
                cnt -= dp[cur-forget];
                cnt = (cnt+mod)%mod;
            }

            dp[cur] = cnt;
        }

        int sum = 0;
        for(int prev=n-forget+1; prev<=n; prev++){
            if(n-forget+1<=0) continue;
            sum += dp[prev]%mod;
            sum %= mod;
        }
        return sum;
    }

    int peopleAwareOfSecret(int nn, int del, int forg) {
        delay = del;
        forget = forg;
        n = nn;
        memset(dp, 0, sizeof(dp));
        return rec();
    }
};