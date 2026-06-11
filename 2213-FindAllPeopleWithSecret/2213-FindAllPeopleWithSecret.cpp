// Last updated: 6/11/2026, 11:24:00 AM
class Solution {
public:
    vector<vector<pair<int, int>>> adjl;
    vector<int> findAllPeople(int n, vector<vector<int>>& arr, int f) {
        adjl.resize(n+1, vector<pair<int, int>>());
        for(auto el: arr){
            int u = el[0];
            int v = el[1];
            int t = el[2];
            adjl[u].push_back({v, t});
            adjl[v].push_back({u, t});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, f});

        for(auto [nei, ti]: adjl[0]){
            pq.push({ti, nei});
        }

        vector<int> vis(n+2, 0);
        vis[0] = 1;

        while(!pq.empty()){
            auto [ti, node] = pq.top(); pq.pop();
            if(vis[node] == 1) continue;
            vis[node] = 1;
            for(auto [nei, neiti]: adjl[node]){
                if(neiti<ti || vis[nei] == 1) continue;
                pq.push({neiti, nei});
            }
        }

        vector<int> ans;
        for(int i=0; i<=n; i++){
            if(vis[i] == 1) ans.push_back(i);
        }

        return ans;

    }
};