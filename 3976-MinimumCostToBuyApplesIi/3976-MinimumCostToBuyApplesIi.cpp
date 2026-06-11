// Last updated: 6/11/2026, 11:14:18 AM
class Solution {
public:
    vector<int> minCost(int n, vector<int>& prices, vector<vector<int>>& roads) {
        vector<int> ans(n, 2e9);
        vector<vector<pair<long long, long long>>> adjlf(n, vector<pair<long long, long long>>());
        vector<vector<pair<long long, long long>>> adjlrev(n, vector<pair<long long, long long>>());

        for(auto edg: roads){
            int u = edg[0];
            int v = edg[1];
            int c1 = edg[2];
            int c2 = edg[3];
            adjlf[u].push_back({v, c1});
            adjlf[v].push_back({u, c1});

            adjlrev[u].push_back({v, 1LL*c1*c2});
            adjlrev[v].push_back({u, 1LL*c1*c2});
        }



        for(int i=0; i<n; i++){
            vector<long long> dist1(n, 1e18);
            vector<long long> dist2(n, 1e18);

            priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>> > pq;

            pq.push({0, i});
            dist1[i] = 0;

            while(!pq.empty()){
                auto [cs, nd] = pq.top(); pq.pop();

                for(auto [nei, neicos]: adjlf[nd]){
                    if(dist1[nei] > dist1[nd] + neicos){
                        dist1[nei] = dist1[nd] + neicos;
                        pq.push({dist1[nei], nei});
                    }
                }
            }

            pq.push({0, i});
            dist2[i] = 0;
            while(!pq.empty()){
                auto [cs, nd] = pq.top(); pq.pop();
                for(auto [nei, neicos]: adjlrev[nd]){
                    if(dist2[nei] > dist2[nd] + neicos){
                        dist2[nei] = dist2[nd] + neicos;
                        pq.push({dist2[nei], nei});
                    }
                }
            }


            long long minans = 2e9;

            for(int j=0; j<n; j++){
                minans = min(minans, dist1[j] + dist2[j] + prices[j]);
            }


            ans[i] = minans;
        }


        return ans;
    }
};