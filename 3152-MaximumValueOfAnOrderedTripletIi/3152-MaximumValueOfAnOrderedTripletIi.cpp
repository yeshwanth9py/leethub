// Last updated: 6/11/2026, 11:19:47 AM

using ll = long long;
class Solution {
public:
    long long maximumTripletValue(vector<int>& num) {
        ll n = num.size();
        vector<ll> nums;
        for(int el: num){
            nums.push_back(el);
        }
        
        vector<ll> maxvl(n, -1e18);
        vector<ll> maxvr(n, -1e18);
        ll ans = 0;
        // for(ll i=1; i<n; i++){
        //     maxvl[i] = max(maxvl[i-1], nums[i-1]);
        // }
        for(ll i=n-2; i>=0; i--){
            maxvr[i] = max(maxvr[i+1], nums[i+1]);
        }
        for(ll i=1; i<n-1; i++){
            maxvl[i] = max(maxvl[i-1], nums[i-1]);
            ans = max(ans, (maxvl[i]-nums[i])*(maxvr[i]));
        }
        return ans;
    }
};