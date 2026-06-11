// Last updated: 6/11/2026, 11:10:24 AM
class Solution {
public:
    string s;
    int n;
    short dp[2501][2501][2];
    int ispalind(int i, int j, int rem){
        if(rem>1) return -1e9;
        if(i<0 || j>=n) return -1e9;
        if(i == 0 || j==n-1){
            if(rem == 1){
                return j-i+1;
            }else{
                if(i == 0 && j==n-1) return j-i+1;
                return j-i+2;
            }
        }

        if(dp[i][j][rem] != -1) return dp[i][j][rem];

        int ans = max({ispalind(i-1, j, rem+1), ispalind(i, j+1, rem+1), j-i+1});
        if(s[i-1] == s[j+1]){
            ans = max(ans, ispalind(i-1, j+1, rem));
        }
        return dp[i][j][rem] = ans;
    }

    int almostPalindromic(string s) {
        n = s.size();
        this->s = s;
        int mx = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                dp[i][j][0] = dp[i][j][1] = -1;
            }
        }
        
        for(int i=0; i<n-1; i++){
            int cl = ispalind(i, i, 0);
            if(s[i] == s[i+1]){
                cl = max(cl, ispalind(i, i+1, 0));
            }else{
                cl = max(cl, ispalind(i, i+1, 1));
            }
            mx = max(mx, cl);
        }

        return mx;
    }
};