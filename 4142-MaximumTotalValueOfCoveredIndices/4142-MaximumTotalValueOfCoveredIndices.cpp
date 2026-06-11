// Last updated: 6/11/2026, 11:12:02 AM
class Solution {
public:
    vector<int> arr;
    string s;
    int n;
    long long dp[100100][2];
    long long rec(int ind, int prev){
        if(ind == n){
            return 0;
        }
        if(dp[ind][prev] != -1) return dp[ind][prev];
        if(ind == 0){
            if(s[ind]=='1'){
                return dp[ind][prev] = arr[ind] + rec(ind+1, 1);
            }else{
                return dp[ind][prev] = rec(ind+1, 0);
            }
        }else{
            long long ans = rec(ind+1, 0);
            if(s[ind] == '1' && prev == 0){
                ans = max(ans, arr[ind-1] + rec(ind+1, 0));
            }

            if(s[ind] == '1'){
                ans = max(ans, arr[ind]+rec(ind+1, 1));
            }
            return dp[ind][prev] = ans;
        }
    }
    
    long long maxTotal(vector<int>& nums, string ss) {
        n = nums.size();
        arr = nums;
        s = ss;
        memset(dp, -1, sizeof(dp));
        long long ans = rec(0, 0);

        return ans;
    }
};