// Last updated: 6/11/2026, 11:26:57 AM
class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long ts = accumulate(nums.begin(), nums.end(), 0LL);
        long long a = ts%p;
        if(a == 0) return 0;
        long long n = nums.size();
        unordered_map<long long, long long> ump;
        long long ans = 1e18;

        long long ps = 0;
        ump[0] = -1;
        for(long long i=0; i<n; i++){
            ps += nums[i]%p;

            long long cur = ps%p - a;
            if(cur<0) cur += p;
            // if(cur == 0){
            //     ans = min(ans, i+1);
            // }
            if(ump.find(cur) != ump.end()){
                ans = min(i - ump[cur], ans);
            }

            ump[ps%p] = i;
        }

        if(ans>=n) return -1;
        return ans;
    }
};

