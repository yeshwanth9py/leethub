// Last updated: 6/11/2026, 11:14:27 AM
class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        long long n = nums.size();
        sort(nums.begin(), nums.end());

        long long minr = n-1;
        for(long long i=0; i<n; i++){
            long long el = nums[i];
            long long bel = el*k;
            auto it = upper_bound(nums.begin(), nums.end(), bel);
            if(it == nums.begin()) continue;
            it--;
            long long ind = it-nums.begin();
            long long rem = n-(ind-i+1);
            minr = min(minr, rem);
        }

        return minr;


    }
};