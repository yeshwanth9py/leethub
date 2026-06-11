// Last updated: 6/11/2026, 11:28:48 AM

using ll = long long;
class Solution {
public:
    bool check(ll mid, vector<int>& candies, long long k){
        ll noc = 0;
        for(ll cand: candies){
            noc += (cand/mid);
        }
        return noc>=k;
    }
    ll maximumCandies(vector<int>& candies, long long k) {
        ll lo = 1;
        ll hi = *max_element(candies.begin(), candies.end());
        ll ans = 0;
        while(lo<=hi){
            ll mid = (lo+hi)/2;
            if(check(mid, candies, k)){
                ans = mid;
                lo = mid+1;
            }else{
                hi = mid-1;
            }
        }

        return ans;
    }
};