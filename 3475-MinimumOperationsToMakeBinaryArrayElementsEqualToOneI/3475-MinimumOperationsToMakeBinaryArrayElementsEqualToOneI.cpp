// Last updated: 6/11/2026, 11:18:05 AM
class Solution {
public:
    void flip(int ind, vector<int> &nums){
        nums[ind] ^= 1;
    }
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int op=0;
        for(int i=0; i<n-2; i++){
            if(nums[i] == 0){
                flip(i, nums);
                flip(i+1, nums);
                flip(i+2, nums);
                op++;
            }
        }
        if(nums[n-1] == 0 || nums[n-2] == 0){
            return -1;
        }
        return op;
    }
};