// Last updated: 6/11/2026, 11:14:26 AM
class Solution {
public:
    int earliestFinishTime(vector<int>& lst, vector<int>& ld, vector<int>& wst, vector<int>& wd) {
        vector<pair<int, int>> land;
        for(int i=0; i<lst.size(); i++){
            land.push_back({lst[i], ld[i]});
        }

        vector<pair<int, int>> water;
        for(int i=0; i<wst.size(); i++){
            water.push_back({wst[i], wd[i]});
        }

        sort(land.begin(), land.end(), [&](pair<int, int> &e1, pair<int, int> &e2){
            return e1.second+e1.first<e2.second+e2.first;
        });

        sort(water.begin(), water.end(), [&](pair<int, int> &e1, pair<int, int> &e2){
            return e1.second+e1.first<e2.second+e2.first;
        });

        int end1 = land[0].first+land[0].second;

        cout<<end1<<" ";
        int ans = 1e9;

        for(int i=0; i<water.size(); i++){
            int waitime = max(water[i].first, end1) - end1;
            ans = min(ans, waitime+end1+water[i].second);
        }

        end1 = water[0].first + water[0].second;

        cout<<end1<<" ";
        for(int i=0; i<land.size(); i++){
            int waitime = max(land[i].first, end1) - end1;
            ans = min(ans, waitime+end1+land[i].second);
        }
        
        return ans;

    }
};