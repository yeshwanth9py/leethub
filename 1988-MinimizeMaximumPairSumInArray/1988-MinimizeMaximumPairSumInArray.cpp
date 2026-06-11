// Last updated: 6/11/2026, 11:25:34 AM
class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int maxs = 0;
        int n = nums.size();
        for(int i=0; i<(nums.size()/2); i++){
            maxs = max(maxs, nums[i]+nums[n-1-i]);
        }

        return maxs;
    }
};