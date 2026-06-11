// Last updated: 6/11/2026, 11:35:20 AM
class Solution {
public:
    vector<int> prices;
    int dp[1001][101][2];
    //tc = st*tran
    //n*k*2*1  = o(n*k);

    //sc = o(n*k);
    int rec(int ind, int rem, bool isbuy){
        if(rem<0){
            return -1e9;
        }
        if(ind == prices.size()){
            return 0;
        }
        if(dp[ind][rem][isbuy]!=-1){
            return dp[ind][rem][isbuy];
        }
        int profit;
        if(isbuy){
            profit = max(-prices[ind]+rec(ind+1, rem, 0), 0+rec(ind+1, rem, 1));
        }else{
            profit = max(prices[ind]+rec(ind+1, rem-1, 1), 0+rec(ind+1, rem, 0));
        }
        return dp[ind][rem][isbuy] = profit;
    }

    int maxProfit(int k, vector<int>& prices) {
        this->prices = prices;
        memset(dp, -1, sizeof(dp));
        return rec(0, k, 1);
    }
};