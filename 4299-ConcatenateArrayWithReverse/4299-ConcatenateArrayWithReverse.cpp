// Last updated: 6/11/2026, 11:09:09 AM
class Solution {
public:
    vector<int> concatWithReverse(vector<int>& nums) {
        vector<int> onums = nums;
        for(int i=nums.size()-1; i>=0; i--){
            onums.push_back(nums[i]);
        }

        return onums;
    }
};