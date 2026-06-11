// Last updated: 6/11/2026, 11:32:05 AM
class Solution {
public:
    int n;
    string s;
    int dp[111][111][27];
    int rec(int l, int r, int latch){
        if(l>r) return 0;
        if(l == r){
            if(latch == s[l]-'a') return 0;
            return 1;
        }

        if(dp[l][r][latch] != -1) return dp[l][r][latch];

        int cos = 1+rec(l+1, r, latch);

        if(s[l]-'a' == latch){
            cos = min(cos, rec(l+1, r, latch));
        }

        for(int j=l; j<=r; j++){
            int cur = 1+rec(l+1, j, s[l]-'a') + rec(j+1, r, latch);
            cos = min(cos, cur);
        }

        return dp[l][r][latch] = cos;
    }

    int strangePrinter(string s) {
        this->s = s;
        n = s.size();
        memset(dp, -1, sizeof(dp));
        return rec(0, n-1, 26);
    }
};