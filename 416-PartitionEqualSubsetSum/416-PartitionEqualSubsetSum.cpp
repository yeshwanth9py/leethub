// Last updated: 6/11/2026, 11:33:13 AM
class Solution {
public:
    int dp[201][20001];
    bool helper(int ind, int sl, vector<int> &nums){
        if(sl<0) return 0;
        
        if(ind == nums.size()){
            return (sl == 0);
        }
        if(dp[ind][sl]!=-1) return dp[ind][sl];

        return dp[ind][sl] = helper(ind+1, sl-nums[ind], nums) || helper(ind+1, sl, nums);
    }


    bool canPartition(vector<int>& nums) {
        int tsum = accumulate(nums.begin(), nums.end(), 0);
        if(tsum%2!=0){
            return 0;
        }

        int hsum = tsum/2;
        for(int i=0; i<=nums.size(); i++){
            for(int j=0; j<=hsum; j++){
                dp[i][j] = -1;
            }
        }

        return helper(0, hsum, nums);

    }
};