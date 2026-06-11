// Last updated: 6/11/2026, 11:15:21 AM
class Solution {
public:
    vector<int> minCosts(vector<int>& cost) {
        vector<int> ans;
        int n = cost.size();
        int mtn = 1e9;
        int sw = 0;
        int psw = 0;
        for(int i=0; i<n; i++){
            if(cost[i]<mtn){
                mtn = cost[i];
                sw = 1;
            }else{
                sw = psw+1;
            }
            ans.push_back(mtn);
            psw = sw;
        }
        return ans;
    }
};