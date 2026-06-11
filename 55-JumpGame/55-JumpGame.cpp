// Last updated: 6/11/2026, 11:37:34 AM
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int mxl = 0;
        for(int i=0; i<n-1; i++){
            mxl = max(mxl, i+nums[i]);
            if(mxl == i) return 0;
        }
        return 1;
    }
};