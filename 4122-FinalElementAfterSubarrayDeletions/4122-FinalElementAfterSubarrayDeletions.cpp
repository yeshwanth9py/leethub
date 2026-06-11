// Last updated: 6/11/2026, 11:12:25 AM
class Solution {
public:
    int finalElement(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        int f = nums[0];
        int l = nums.back();
        return max(f, l);
    }
};