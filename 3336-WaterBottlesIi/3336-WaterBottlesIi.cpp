// Last updated: 6/11/2026, 11:18:44 AM
class Solution {
public:
    int dp[201][201][201];
    int rec(int nb, int eb, int ex){
        if(nb == 0 && eb == 0){
            return 0;
        }
        if(dp[nb][eb][ex] != -1) return dp[nb][eb][ex];
        if(nb>0){
            return dp[nb][eb][ex] = nb + rec(0, eb+nb, ex);
        }else{
            if(eb>=ex){
                return dp[nb][eb][ex] = rec(1, eb-ex, ex+1);
            }else{
                return dp[nb][eb][ex] = 0;
            }
        }
    }

    int maxBottlesDrunk(int nb, int ex) {
        memset(dp, -1, sizeof(dp));
        return rec(nb, 0, ex);
    }
};