// Last updated: 6/11/2026, 11:14:21 AM
class Solution {
public:
    const int mod = 1e9+7;
    int binpow(int x, int n){
        if(n == 0) return 1;
        int ans = binpow(x, n/2);
        ans = ((1LL*ans*ans)%mod + mod)%mod;
        if(n&1){
            ans = ((1LL*ans*x)%mod + mod)%mod;
        }
        return ans;
    }

    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& q) {
        int n = nums.size();
        int k = sqrt(n)+1;
        vector<vector<vector<int>>> vec(k+1, vector<vector<int>>());
        for(auto el: q){
            int l = el[0];
            int r = el[1];
            int j = el[2];
            int v = el[3];
            if(j<=k){
                vec[j].push_back({l, r, v});
            }else{
                for(int i=l; i<=r; i=i+j){
                    nums[i] = ((1LL*nums[i]*(v))%mod + mod)%mod;
                }
            }
        }

        for(int j=1; j<=k; j++){
            vector<int> diff(n, 1);
            for(auto el: vec[j]){
                int l = el[0];
                int r = el[1];
                int v = el[2];
                
                diff[l] = ((1LL*diff[l]*v)%mod + mod)%mod;
                int cnt = (r-l)/j + 1;
                int ei = l + (cnt*j);
                if(ei<n){
                    diff[ei] = ((1LL*diff[ei]*binpow(v, mod-2))%mod + mod)%mod;
                }
            }
            for(int i=0; i<n; i++){
                diff[i] = ((1LL*diff[i]*((i-j>=0?diff[i-j]:1)))%mod + mod)%mod;
            }

            for(int i=0; i<n; i++){
                nums[i] = ((1LL*nums[i]*diff[i])%mod + mod)%mod;
            }
        }

        int ans = 0;
        for(int i=0; i<n; i++){
            ans = ans ^ nums[i];
        }

        return ans;

    }
};