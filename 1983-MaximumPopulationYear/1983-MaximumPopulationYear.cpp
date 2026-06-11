// Last updated: 6/11/2026, 11:25:38 AM
class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<pair<int, int>> sweep;
        for(auto vec: logs){
            int s = vec[0];
            int e = vec[1];
            sweep.push_back({s, 1});
            sweep.push_back({e, -1});
        }
        sort(sweep.begin(), sweep.end());
        int maxp = 0;
        int curp = 0;
        int yr = 0;
        for(int i=0; i<sweep.size(); i++){
            curp += sweep[i].second;
            if(curp>maxp){
                yr = sweep[i].first;
                maxp = curp;
            }
        }

        return yr;
    }
};