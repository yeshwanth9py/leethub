// Last updated: 6/11/2026, 11:24:38 AM
class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size();
        int maxel = nums[n-1];
        int maxd = -1;
        for(int i=n-2; i>=0; i--){
            if(nums[i]<maxel) {
                maxd = max(maxd, maxel-nums[i]);
            }
            maxel = max(maxel, nums[i]);
        }
        // if(maxd<0) return -1?;
        return maxd;
    }
};