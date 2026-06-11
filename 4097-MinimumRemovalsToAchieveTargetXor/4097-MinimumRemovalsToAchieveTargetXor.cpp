// Last updated: 6/11/2026, 11:12:47 AM
class Solution {
public:
    int n;
    int targ;
    vector<int> arr;
    int dp[41][101000];
    int rec(int ind, int curx){
        
        if(ind == n){
            // cout<<curx<<endl;
            if(curx == targ){
                return 0;
            }
            return 1e9;
        }
        if(dp[ind][curx] != -1) return dp[ind][curx];
        int ans = rec(ind+1, curx^arr[ind]);
        ans = min(ans, 1+rec(ind+1, curx));
        return dp[ind][curx] = ans;
    }
    
    int minRemovals(vector<int>& nums, int target) {
        n = nums.size();
        targ = target;
        arr = nums;
        memset(dp, -1, sizeof(dp));
        int ans = rec(0, 0);
        if(ans>=n){
            if(targ == 0) return ans;
            return -1;
        }
        return ans;
    }
};