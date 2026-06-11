// Last updated: 6/11/2026, 11:21:16 AM
class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        long long cnt = 0;
        for(int i=0; i<n; i++){
            int cur = nums[i];
            int curlo = lower-nums[i];
            int curup = upper-nums[i];
            long long loind = lower_bound(nums.begin()+i+1, nums.end(), curlo)-nums.begin();
            long long upind = upper_bound(nums.begin()+i+1, nums.end(), curup)-nums.begin();
            cnt += upind-loind;
        }
        return cnt;
    }
};