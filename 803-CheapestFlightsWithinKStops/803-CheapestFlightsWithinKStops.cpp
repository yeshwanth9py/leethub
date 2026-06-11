// Last updated: 6/11/2026, 11:31:11 AM
class Solution {
public:
    vector<vector<pair<int, int>>> adjl;
    int findCheapestPrice(int n, vector<vector<int>>& fli, int src, int dst, int k) {
        adjl.resize(n, vector<pair<int, int>>());

        for(auto el: fli){
            int u = el[0];
            int v = el[1];
            int wt = el[2];
            adjl[u].push_back({v, wt});
        }

        vector<vector<int>> dist(n, vector<int>(k+1, 1e9));

        dist[src][0] = 0;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>> > pq;
        pq.push({0, -1, src});

        while(!pq.empty()){
            auto tn = pq.top(); pq.pop();
            int di = tn[0];
            int st = tn[1];
            int nd = tn[2];

            if(st+1>k) continue;

            for(auto [nei, adjwt]: adjl[nd]){
                if(dist[nei][st+1] > di + adjwt){
                    dist[nei][st+1] = di + adjwt;
                    pq.push({dist[nei][st+1], st+1, nei});
                }
            }
        }

        int mind = 1e9;

        
        for(int i=0; i<=k; i++){
            mind = min(mind, dist[dst][i]);
        }

        if(mind >= 1e8) return -1;
        return mind;
    }
};