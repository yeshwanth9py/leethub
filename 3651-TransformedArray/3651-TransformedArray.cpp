// Last updated: 6/11/2026, 11:17:01 AM
class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0);

        for(int i=0; i<n; i++){
            int j = abs(nums[i])%n;
            if(nums[i]<0){
                int ni = i-j;
                if(ni>=0){
                    ans[i] = nums[ni];
                }else{
                    ans[i] = nums[n+ni];
                }
            }else if(nums[i] == 0){
                ans[i] = nums[i];
            }else{
                int ni = i+j;
                if(ni<n){
                    ans[i] = nums[ni];
                }else{
                    ans[i] = nums[ni%n];
                }
            }
        }

        return ans;


    }
};