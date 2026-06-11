// Last updated: 6/11/2026, 11:37:31 AM
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& interv) {
        vector<vector<int>> all;
        int n = interv.size();
        sort(interv.begin(), interv.end());
        int i = 0;
        while(i<n){
            int st = interv[i][0];
            int en = interv[i][1];
            int j = i;
            while(j<n){
                if(interv[j][0]<=en){
                    en = max(en, interv[j][1]);
                }else{
                    break;
                }
                j++;
            }
            all.push_back({st, en});
            i = j;
        }

        return all;
    }
};