// Last updated: 6/11/2026, 11:21:29 AM
class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        long long n = nums.size();
        long long ps = 0;
        long long ans = 0;
        unordered_map<long long, long long> ump;
        ump[0] = 1;
        for(long long i=0; i<n; i++){
            ps ^= nums[i];
            if(ump.find(ps) != ump.end()){
                ans += ump[ps];
            }
            ump[ps]++;
        }

        return ans;
    }
};

