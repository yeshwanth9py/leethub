// Last updated: 6/11/2026, 11:32:50 AM
class Solution {
public:
    string s;
    int dp[1001][1001];
    int rec(int i, int j){
        if(i==j) return 1;
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int maxlen = 0;
        if(s[i] == s[j]){
            maxlen = max(maxlen, 2+rec(i+1, j-1));
        }
        maxlen = max(maxlen, rec(i+1, j));
        maxlen = max(maxlen, rec(i, j-1));
        return dp[i][j] = maxlen;
    }

    int longestPalindromeSubseq(string s) {
        this->s = s;
        memset(dp, -1, sizeof(dp));
        return rec(0, s.length()-1);
    }
};
