// Last updated: 6/11/2026, 11:20:51 AM
class Solution {
public:
    bool sumd(int ind, string str, int cursum, int target, vector<vector<int>> &dp){
        if(ind == str.length()){
            if(cursum == target){
                return true;
            }
            return false;
        }

        if(cursum>target) return false;

        if(dp[ind][cursum]!=-1){
            return dp[ind][cursum];
        }

        for(int i=ind; i<str.length(); i++){
            if(sumd(i+1, str, cursum+stoi(str.substr(ind, i-ind+1)), target, dp)){
                return dp[ind][cursum] = true;
            }
        }

        return dp[ind][cursum] = false;


    }
    int punishmentNumber(int n) {
        int ans = 0;
        for(int i=1; i<=n; i++){
            string str = to_string(i*i);
            vector<vector<int>> memo(str.length(), vector<int>(i+1, -1));
            if(sumd(0, str, 0, i, memo)){
                ans += i*i;
            }
        }
        return ans;
    }
};