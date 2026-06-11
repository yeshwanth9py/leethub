// Last updated: 6/11/2026, 11:14:20 AM
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

    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& qu) {
        int n = nums.size();
        int k = sqrt(n) + 1;
        vector<vector<int>> sq;
        for(auto q: qu){
            int l = q[0];
            int r = q[1];
            int j = q[2];
            int v = q[3];
            if(j<=k){
                sq.push_back({l, r, j, v});
            }else{
                for(int i=l; i<=r; i+=j){
                    nums[i] = ((1LL*nums[i]*v)%mod + mod)%mod;
                }
            }
        }

        vector<vector<int>> difmat(k+1, vector<int>(n, 1));
        for(auto el: sq){
            int l = el[0];
            int r = el[1];
            int j = el[2];
            int v = el[3];

            difmat[j][l] = ((1LL*difmat[j][l] * v)%mod + mod)%mod;
            int cnt = (r-l)/j + 1;
            int ei = l+cnt*j;
            if(ei<n){
                difmat[j][ei] = ((1LL*difmat[j][ei] * binpow(v, mod-2))%mod + mod)%mod;
            }
        }

        for(int j=1; j<=k; j++){
            for(int i=0; i<n; i++){
                difmat[j][i] = ((1LL*difmat[j][i]*(i-j>=0?difmat[j][i-j]:1LL))%mod + mod)%mod;
            }
        }

        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=1; j<=k; j++){
                nums[i] = ((1LL*nums[i]*difmat[j][i])%mod + mod)%mod;
            }
            ans ^= nums[i];
        }

        return ans;
    }
};