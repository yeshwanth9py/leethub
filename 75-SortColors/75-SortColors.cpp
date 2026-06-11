// Last updated: 6/11/2026, 11:37:11 AM
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int lo = 0;
        int hi=nums.size()-1;
        int i = 0;

        while(i<=hi){
            if(nums[i] == 0){
                swap(nums[lo], nums[i]);
                lo++;
                if(i<lo){
                    i++;
                }
            }else if(nums[i] == 2){
                swap(nums[hi], nums[i]);
                hi--;
            }else if(nums[i] == 1){
                i++;
            }
        }

    }
};