// Last updated: 6/11/2026, 11:15:14 AM
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum>=k){
            int div = sum/k;
            return sum-(k*div);
        }else{
            return sum;
        }
    }
};