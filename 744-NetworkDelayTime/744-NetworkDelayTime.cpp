// Last updated: 6/11/2026, 11:31:35 AM
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adjl(n+1, vector<pair<int, int>>());

        for(auto sv: times){
            adjl[sv[0]].push_back({sv[1], sv[2]});
        }

        vector<int> dist(n+1, 1e9);
        dist[k] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});
        while(!pq.empty()){
            auto [cd, cn] = pq.top();
            pq.pop();
            if(cd > dist[cn]){
                continue;
            }
            
            for(auto el: adjl[cn]){
                int nn = el.first;
                int nd = el.second;
                if(dist[nn]>dist[cn]+nd){
                    dist[nn] = dist[cn]+nd;
                    pq.push({dist[nn], nn});
                }
            }
        }

        int maxd = 0;
        for(int i=1; i<=n; i++){
            maxd = max(maxd, dist[i]);
        }

        if(maxd == 1e9){
            return -1;
        } 
        return maxd;
    }
};