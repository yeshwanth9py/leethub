// Last updated: 6/11/2026, 11:26:33 AM
class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int maxw = 0;
        for(int i=0; i<accounts.size(); i++){
            maxw = max(maxw, accumulate(accounts[i].begin(), accounts[i].end(), 0));
        }

        return maxw;
    }
};