// Last updated: 6/11/2026, 11:27:23 AM
class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
        unordered_map<int, vector<int>> occ;
        vector<int> ans(n, -1);

        for(int i=0; i<n; i++){
            if(rains[i] != 0){
                occ[rains[i]].push_back(i);
            }
        }

        for(int i=0; i<n; i++){
            if(rains[i] != 0){
                auto nxt = upper_bound(occ[rains[i]].begin(), occ[rains[i]].end(), i);
                if(nxt == occ[rains[i]].end()) continue;
                pq.push({*nxt, rains[i]});
            }else{
                if(!pq.empty()){
                    auto [pos, val] = pq.top(); pq.pop();
                    if(pos<i){
                        return {};
                    }else{
                        ans[i] = val;
                    }
                }else{
                    ans[i] = 1;
                }
            }
        }

        if(pq.empty()) return ans;
        return {};





    }
};