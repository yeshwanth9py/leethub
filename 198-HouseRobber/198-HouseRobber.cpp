// Last updated: 6/11/2026, 11:35:10 AM
class Solution {
public:
    int dp[101][2];
    int rob(vector<int>& nums) {
        int n = nums.size();
        for(int i=n; i>=0; i--){
            if(i == n){
                dp[i][0] = dp[i][1] = 0;
                continue;
            }
            dp[i][0] = max(dp[i+1][0], dp[i+1][1]);
            dp[i][1] = nums[i]+dp[i+1][0];
        }

        return max(dp[0][0], dp[0][1]);
    }
};