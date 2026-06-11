// Last updated: 6/11/2026, 11:22:31 AM
using ll = long long;
class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        unordered_map<ll, ll> ump;
        ll bp = 0;
        for(ll i=0; i<nums.size(); i++){
            if(i){
                ll ts = i;
                if(ump.find(nums[i]-i)!=ump.end()){
                    ts -= ump[nums[i]-i];
                }
                bp += ts;
            }
            ump[nums[i]-i]++;
        }
        return bp;
    }
};