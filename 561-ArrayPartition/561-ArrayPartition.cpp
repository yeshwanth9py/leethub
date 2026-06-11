// Last updated: 6/11/2026, 11:32:29 AM
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int sum1 = 0;
        for(int i=0; i<nums.size()-1; i=i+2){
            int el1 = nums[i];
            int el2 = nums[i+1];
            sum1 += min(el1, el2);
        }
        return sum1;
        
    }
};