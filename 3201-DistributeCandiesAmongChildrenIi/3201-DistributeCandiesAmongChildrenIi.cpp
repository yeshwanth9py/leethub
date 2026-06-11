// Last updated: 6/11/2026, 11:19:27 AM
class Solution {
public:
    
    long long distributeCandies(int n, int limit) {
        long long dp[n+1][4];
        memset(dp,0,sizeof(dp));
        dp[0][0]=1;
        for(int j=0;j<3;j++){
              long long temp=0;
              for(int i=0;i<=n;i++){
              dp[i][j+1]+=temp+dp[i][j];
              if(i-limit-1>=0)dp[i][j+1]-=dp[i-limit-1][j];
              temp+=dp[i][j];
              if(i-1>=0)dp[i][j]+=dp[i-1][j];
        }
    }
    return dp[n][3];   
    }
};