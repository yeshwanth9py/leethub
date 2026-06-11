// Last updated: 6/11/2026, 11:31:08 AM
class Solution {
public:
    int n;
    long long mod = 1e9+7;
    long long dp[1001][1001];
    Solution(){
        memset(dp, -1, sizeof(dp));
    }
    long long rec(int t, int b){
        // cout<<t<<" "<<b<<endl;
        if(t>n || b>n) return 0;
        if(t==n && b==n) return 1;
        if(dp[t][b]!=-1) return dp[t][b];
        if(t>b){
            return dp[t][b] = (rec(t+1, b+2)%mod+rec(t, b+2)%mod)%mod;
        }else if(b>t){
            return dp[t][b] = (rec(t+2, b+1)%mod+rec(t+2, b)%mod)%mod;
        }else{
            return dp[t][b] = (rec(t+1, b+1)%mod+rec(t+2, b+2)%mod+rec(t+2, b+1)%mod+rec(t+1, b+2)%mod)%mod;
        }
    }

    int numTilings(int n) {
        this->n = n;
        return rec(0, 0);
    }
};