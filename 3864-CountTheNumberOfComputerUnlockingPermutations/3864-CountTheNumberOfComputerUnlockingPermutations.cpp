// Last updated: 6/11/2026, 11:15:03 AM
class Solution {
public:
    long long dp[100100];
    int mod = 1e9+7;
    long long fact(int n){
        if(n<=1){
            return 1;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        return dp[n] = (n%mod*fact(n-1)%mod)%mod;
    }
    int countPermutations(vector<int>& comp) {
        int minind = 0;
        int n = comp.size();
        for(int i=1; i<n; i++){
            if(comp[i]<=comp[minind]){
                return 0;
            }
        }
        memset(dp, -1, sizeof(dp));
        return fact(n-1)%mod;
        
    }
};