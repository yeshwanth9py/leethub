// Last updated: 6/11/2026, 11:34:11 AM
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int xorr = 0;
        for(int i=0; i<nums.size(); i++){
            xorr = xorr ^ (nums[i]^i);  
        }

        return nums.size()^xorr;
    }
};