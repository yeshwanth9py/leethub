// Last updated: 6/11/2026, 11:22:33 AM
class Solution {
public:
    vector<vector<int>> dp;
    int longest_sub(string& s, int ind, int prev, int k) {
        if (ind == s.size()) {
            return 0; 
        }

        if (dp[ind][prev + 1] != -1) return dp[ind][prev + 1];

        int result = longest_sub(s, ind + 1, prev, k); 

        char ch = static_cast<char>(97+prev);

        if (prev == -1 || abs(ch - s[ind]) <= k) {
            result = max(result, 1 + longest_sub(s, ind + 1, s[ind]-'a', k));
        }

        return dp[ind][prev + 1] = result;
    }

    int longestIdealString(string s, int k) {
        dp.resize(s.size()+2, vector<int>(28, -1));
        return longest_sub(s, 0, -1, k);
    }   


};