// Last updated: 6/11/2026, 11:25:20 AM
using ll = long long;
class Solution {
public:
    ll rec(ll ind, vector<int> &nums, ll par, vector<vector<ll>> &dp){
        if(ind == nums.size()){
            return 0;
        }
        if(dp[ind][par]!=-1){
            return dp[ind][par];
        }
        if(par==0){
            ll take = nums[ind]+rec(ind+1, nums, 1, dp);
            ll not_take = rec(ind+1, nums, par, dp);
            return dp[ind][par] = max(take, not_take);
        }else{
            ll take = -nums[ind]+rec(ind+1, nums, 0, dp);
            ll not_take = rec(ind+1, nums, par, dp);
            return dp[ind][par] = max(take, not_take);
        }
    }
    long long maxAlternatingSum(vector<int>& nums) {
        ll n = nums.size();
        vector<vector<ll>> dp(n, vector<ll>(2, -1));
        return rec(0, nums, 0, dp);
    }
};