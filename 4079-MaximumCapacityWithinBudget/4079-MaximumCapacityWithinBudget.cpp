// Last updated: 6/11/2026, 11:13:01 AM
class Solution {
public:
    int maxCapacity(vector<int>& cost, vector<int>& cap, int budg) {
        int n = cap.size();
        vector<pair<int, int>> vec, vec2;
        for(int i=0; i<n; i++){
            vec.push_back({cost[i], cap[i]});
            vec2.push_back({cost[i], cap[i]});
        }

        sort(vec.begin(), vec.end());
        sort(vec2.begin(), vec2.end());

        int mc = 0;
        for(int i=0; i<vec.size(); i++){
            mc = max(mc, vec[i].second);
            vec[i].second = mc;
        }

        int ans = 0;
        for(int i=0; i<n; i++){
            if(vec2[i].first>=budg) continue;
            ans = max(ans, vec2[i].second);
            int remc = budg-vec2[i].first-1;
            auto it = upper_bound(vec.begin(), vec.begin()+i, make_pair(remc, 1e9));
            if(it == vec.begin()) continue;
            it--;
            ans = max(ans, (*it).second+vec2[i].second);
        }

        return ans;



    }
};