// Last updated: 6/11/2026, 11:19:45 AM

using ll = long long;
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        ll maxd = -1e18;
        ll mind = 1e18;
        vector<ll> numstn;
        ll ans = 0;
        for(ll i=0; i<n; i++){
            if(maxd != -1e18){
                ll curans = max(nums[i]*(mind), nums[i]*maxd);
                ans = max(ans, curans);
            }
            for(ll j=0; j<numstn.size(); j++){
                maxd = max(maxd, numstn[j]-nums[i]);
                mind = min(mind, numstn[j]-nums[i]);
            }
            numstn.push_back(nums[i]);
        }

        return ans;
    }
};