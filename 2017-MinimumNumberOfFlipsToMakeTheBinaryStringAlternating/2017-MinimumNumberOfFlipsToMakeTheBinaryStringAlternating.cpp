// Last updated: 6/11/2026, 11:25:22 AM
class Solution {
public:
    int dp[200200][2];
    int n;
    int minFlips(string s) {
        n = s.size();
        for(int i=n-1; i>=0; i--){
            if(s[i] == '0'){
                dp[i][0] = 0;
                dp[i][1] = 1;
            }else{
                dp[i][0] = 1;
                dp[i][1] = 0;
            }
            if(i+1<n){
                dp[i][0] += dp[i+1][1];
                dp[i][1] += dp[i+1][0];
            }
        }

        int ans = min(dp[0][0], dp[0][1]);

        for(int i=1; i<n; i++){
            //conv to 1
            int c1 = dp[i][1];
            if((i%2)==(n-1)%2){
                c1 += (dp[0][0]);
                if(i%2 == 0){
                    c1 -= dp[i][0];
                }else{
                    c1 -= dp[i][1];
                }
            }else{
                c1 += dp[0][1];
                if(i%2 == 0){
                    c1 -= dp[i][1];
                }else{
                    c1 -= dp[i][0];
                }
            }

            //conv to 0
            int c2 = dp[i][0];
            if((i%2)==(n-1)%2){
                c2 += (dp[0][1]);
                if(i%2 == 0){
                    c2 -= dp[i][1];
                }else{
                    c2 -= dp[i][0];
                }
            }else{
                c2 += dp[0][0];
                if(i%2 == 0){
                    c2 -= dp[i][0];
                }else{
                    c2 -= dp[i][1];
                }
            }

            ans = min({ans, c1, c2});
        }

        return ans;


    }
};