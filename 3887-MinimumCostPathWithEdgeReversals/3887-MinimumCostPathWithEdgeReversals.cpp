// Last updated: 6/11/2026, 11:14:50 AM
class Solution {
public:
    vector<vector<pair<int, int>>> adjl;
    int minCost(int n, vector<vector<int>>& edges) {
        adjl.resize(n, vector<pair<int, int>>());
        for(auto ed: edges){
            int u = ed[0];
            int v = ed[1];
            int w = ed[2];
            adjl[u].push_back({v, w});
            adjl[v].push_back({u, 2*w});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0});
        vector<int> dist(n, 1e9);
        dist[0] = 0;
        while(!pq.empty()){
            auto [wt, nd] = pq.top(); pq.pop();
            for(auto [nei, neiwt]: adjl[nd]){
                if(dist[nei]>dist[nd]+neiwt){
                    dist[nei] = dist[nd]+neiwt;
                    pq.push({dist[nei], nei});
                }
            }
        }

        // for(int i=0; i<n; i++){
        //     cout<<dist[i]<<" ";
        // }
        // cout<<endl;
        if(dist[n-1] == 1e9) return -1;
        return dist[n-1];
    }
};