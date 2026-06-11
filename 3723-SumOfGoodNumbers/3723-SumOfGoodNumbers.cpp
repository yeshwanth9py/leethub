// Last updated: 6/11/2026, 11:16:36 AM
class Solution {
public:
    int sumOfGoodNumbers(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        for(int i=0; i<n; i++){
            if(i-k>=0 && i+k<n){
                if(nums[i]>nums[i-k] && nums[i]>nums[i+k]){
                    ans += nums[i];   
                }
            }else if(i-k>=0){
                if(nums[i]>nums[i-k]){
                    ans += nums[i];
                }
            }else if(i+k<n){
                if(nums[i]>nums[i+k]){
                    ans += nums[i];
                }
            }else{
                ans += nums[i];
            }
        }

        return ans;

        
    }
};