// Last updated: 6/11/2026, 11:25:03 AM

using ll = long long;

class Solution {
public:
    ll mod = 1e9+7;
    vector<vector<pair<ll, ll>>> adjl;

    int countPaths(int n, vector<vector<int>>& roads) {
        vector<ll> dist(n, 1e18);
        vector<ll> ways(n, 0);
        adjl.resize(n, vector<pair<ll, ll>>());
        for(auto ele: roads){
            ll u = ele[0];
            ll v = ele[1];
            ll t = ele[2];
            adjl[u].push_back({v, t});
            adjl[v].push_back({u, t});
        }

        ways[0] = 1;
        dist[0] = 0;
        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
        pq.push({0, 0});
        while(!pq.empty()){
            auto [td, tn] = pq.top(); pq.pop();
            if(dist[tn]<td) continue;
            for(auto [nei, nti]: adjl[tn]){
                if(dist[nei]>dist[tn]+nti){
                    dist[nei]=((dist[tn]+nti));
                    ways[nei] = ways[tn]%mod;
                    pq.push({dist[nei], nei});
                }else if(dist[nei]==dist[tn]+nti){
                    ways[nei] = ((ways[tn]+ways[nei])%mod+mod)%mod;
                }
            }
        }

        return ways[n-1]%mod;


    }
};