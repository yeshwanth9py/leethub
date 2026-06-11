// Last updated: 6/11/2026, 11:27:10 AM
class Solution {
public:
    int e;
    int dp[101][101];
    int rec(int num, int rem){
        if(num == 0) return 0;
        if(dp[num][rem]!=-1) return dp[num][rem];
        int nonfb = ((num+rem)/e);
        int nex = (num+rem)%e;
        return dp[num][rem] = num + rec(nonfb, nex);
    }

    int numWaterBottles(int b, int n) {
        e = n;
        memset(dp, -1, sizeof(dp));
        return rec(b, 0);
    }
};