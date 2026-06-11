// Last updated: 6/11/2026, 11:34:07 AM
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int sl = nums[0];
        int fs = nums[0];
        sl = nums[sl];
        fs = nums[nums[fs]];
        while(sl!=fs){
            sl = nums[sl];
            fs = nums[nums[fs]];
        }

        sl = nums[0];
        while(sl!=fs){
            sl = nums[sl];
            fs = nums[fs];
        }

        return sl;

    }
};