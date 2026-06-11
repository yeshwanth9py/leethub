// Last updated: 6/11/2026, 11:21:56 AM
class Solution {
public:
    string s;
    int dp[2001][2001];
    int n;
    int k;
    int ispal(int i, int j){
        if(i >= j) return dp[i][j] = 1;
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i] == s[j]){
            return dp[i][j] = ispal(i+1, j-1);
        }else{
            return dp[i][j] = 0;
        }
    }

    int dp3[2001];
    int rec(int ind){
        if(ind == n) return 0;
        if(dp3[ind] != -1) return dp3[ind];
        int ans = rec(ind+1);
        
        for(int i=ind+k-1; i<n; i++){
            if(ispal(ind, i)){
                ans = max(ans, 1+rec(i+1));
            }
        }
        return dp3[ind] = ans;
    }
    
    int maxPalindromes(string ss, int kk) {
        s = ss;
        n = s.size();
        k = kk;
        for(int i=0; i<=n; i++){
            for(int j=0; j<=n; j++){
                dp[i][j] = -1;
            }
            dp3[i] = -1;
        }

        return rec(0);

        
    }
};