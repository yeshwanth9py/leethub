// Last updated: 6/11/2026, 11:25:45 AM
class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n = nums.size();
        int j = 0;
        int cursum = nums[0];
        int maxsum = cursum;
        while(j<n){
            cursum = nums[j];
            maxsum = max(maxsum, cursum);
            while(j+1<n && nums[j+1]>nums[j]){
                j++;
                cursum += nums[j];
                maxsum = max(maxsum, cursum);
            }
            j++;
        }
        return maxsum;
    }
};