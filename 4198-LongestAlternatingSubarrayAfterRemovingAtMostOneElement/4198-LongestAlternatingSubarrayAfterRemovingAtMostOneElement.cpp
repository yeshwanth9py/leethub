// Last updated: 6/11/2026, 11:10:46 AM
class Solution {
public:
    int dp[100111][2];
    int dpr[100111][2];
    int longestAlternating(vector<int>& nums) {
        int n = nums.size();
        memset(dp, 0, sizeof(dp));
        memset(dpr, 0, sizeof(dpr));
        int ans = 0;
        for(int i=n-2; i>=0; i--){
            if(nums[i]<nums[i+1]){
                dp[i][1] = dp[i+1][0] + 1;
                dp[i][0] = 0;
            }else if(nums[i]>nums[i+1]){
                dp[i][0] = dp[i+1][1] + 1;
                dp[i][1] = 0;
            }else{
                dp[i][0] = dp[i][1] = 0;
            }
            ans = max({ans, dp[i][0]+1, dp[i][1]+1});
        }
        
        for(int i=1; i<n; i++){
            if(nums[i]<nums[i-1]){
                dpr[i][1] = dpr[i-1][0] + 1;
                dpr[i][0] = 0;
            }else if(nums[i]>nums[i-1]){
                dpr[i][0] = dpr[i-1][1] + 1;
                dpr[i][1] = 0;
            }else{
                dpr[i][0] = dpr[i][1] = 0;
            }
             ans = max({ans, dpr[i][0]+1, dpr[i][1]+1});
        }

        for(int i=1; i<n-1; i++){
            if(nums[i-1]<nums[i+1]){
                ans = max(ans, dpr[i-1][1] + dp[i+1][0] + 2);
            }else if(nums[i-1]>nums[i+1]){
                ans = max(ans, dpr[i-1][0] + dp[i+1][1] + 2);
            }
        }

        return ans;

    
        
        
    }
};