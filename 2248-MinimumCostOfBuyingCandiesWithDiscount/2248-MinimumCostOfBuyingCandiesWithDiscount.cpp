// Last updated: 6/11/2026, 11:23:47 AM
class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(), cost.end());
        int n = cost.size();

        int i = n-1;
        int tot = 0;

        for(i=n-1; i>=0;){
            tot += cost[i];
            i--;
            if(i>=0){
                tot += cost[i];
            }
            i = i-2;
        }

        return tot;
    }
};