// Last updated: 6/11/2026, 11:25:29 AM

using ll = long long;
class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        ll n = nums.size();
        ll ans = 0;
        for(ll i=0; i<30; i++){
            ll noo = 0;
            for(ll j=0; j<n; j++){
                if((nums[j]&(1<<i)) != 0){
                    noo++;
                }
            }
            if(noo==0){
                continue;
            }
            int tot = ((1<<(noo))/2)*(1<<(n-noo));
            ans += (1<<i)*(tot);
        }

        return ans;
    }
};