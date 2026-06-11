// Last updated: 6/11/2026, 11:31:47 AM
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int i = 0;
        int j = -1;
        int curp = 1;
        int cnt = 0;
        int n = nums.size();
        while(i<n){
            while(j+1<n && curp*nums[j+1]<k){
                j++;
                curp *= nums[j];
            }
            if(j-i+1>=0){
                cnt += (j-i+1);
            }
            if(i>j){
                i++;
                j = i-1;
            }else{
                curp /= nums[i];
                i++;
            }
        }

        return cnt;
    }
};