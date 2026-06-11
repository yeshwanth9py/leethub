// Last updated: 6/11/2026, 11:36:19 AM
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sm = 1e9;
        int mp = -1e9;
        for(int i=0; i<prices.size(); i++){
            if(prices[i]>=sm){
                mp = max(mp, prices[i]-sm);
            }
            sm = min(sm, prices[i]);
        }

        return ((mp<=0)?0:mp);
    }
};