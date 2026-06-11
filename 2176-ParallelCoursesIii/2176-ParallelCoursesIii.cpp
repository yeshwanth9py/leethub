// Last updated: 6/11/2026, 11:24:18 AM
class Solution {
public:
    vector<vector<int>> adjl;
    int minimumTime(int n, vector<vector<int>>& rel, vector<int>& time) {
        queue<int> pq;
        adjl.resize(n, vector<int>());
        vector<int> indeg(n, 0);
        for(auto el: rel){
            int a = el[0];
            int b = el[1];
            a--;
            b--;
            adjl[a].push_back(b);
            indeg[b]++;
        }
        vector<int> dist(n, 0);
        for(int i=0; i<n; i++){
            if(indeg[i] == 0){
                pq.push(i);
                dist[i] = time[i];
            }
        }

        int ans = 0;
        while(!pq.empty()){
            auto nd = pq.front(); pq.pop();
            
            for(int nei: adjl[nd]){
                indeg[nei]--;
                dist[nei] = max(dist[nei], dist[nd]+time[nei]);
                if(indeg[nei] == 0){
                    pq.push(nei);
                }
            }
        }
        ans = *(max_element(dist.begin(), dist.end()));
        return ans;
    }
};