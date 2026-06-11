// Last updated: 6/11/2026, 11:24:21 AM
class Solution {
public:
    int ans;
    vector<int> nums;
    int n;
    int dp[17][1001000];
    int rec(int ind, int xs){
        if(ind == n){
            if(xs == ans){
                return 1;
            }
            return 0;
        }

        if(dp[ind][xs]!=-1) return dp[ind][xs];
        return dp[ind][xs] = rec(ind+1, (xs | nums[ind])) + rec(ind+1, xs);
    }


    int countMaxOrSubsets(vector<int>& nums) {
        ans = 0;
        n = nums.size();
        this->nums = nums;
        for(int el: nums){
            ans |= el;
        }

        memset(dp, -1, sizeof(dp));
        

        return rec(0, 0);


        // return 0;
    }
};