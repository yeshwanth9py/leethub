// Last updated: 6/11/2026, 11:22:04 AM
class Solution {
public:
    const int mod = 1e9+7;
    int binpow(int x, int n){
        if(n == 0){
            return 1;
        }
        if(x == 0) return 0;
        int ans = binpow(x, n/2)%mod;
        ans = (1LL*(ans%mod) * (ans%mod))%mod;
        if(n&1){
            ans = (1LL*ans*x)%mod;
        }
        return ans;
    }

    vector<int> productQueries(int n, vector<vector<int>>& quer) {
        vector<int> pref;
        int prod = 1;

        for(int i=0; i<31; i++){
            if((n&(1LL<<i))){
                int cur = ((1LL<<i));
                prod = (1LL*cur*prod)%mod;
                pref.push_back(prod);
            }
        }
        

        vector<int> ans;
        for(auto el: quer){
            int si = el[0];
            int ei = el[1];
            int cur = pref[ei]%mod;
            if(si-1>=0){
                cur = (1LL*cur*binpow(pref[si-1], mod-2))%mod;
            }

            ans.push_back(cur);
        }

        return ans;
    }
};