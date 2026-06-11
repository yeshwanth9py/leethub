// Last updated: 6/11/2026, 11:12:40 AM
class Solution {
public:
    vector<vector<pair<int, int>>> adjl;
    int n;
    int src;
    int tgt;
    
    long long bfs(long long node, long long md){
        vector<long long> dist(n, 1e9);
        dist[src] = 0;
        queue<long long> q;
        q.push(src);
        
        while(!q.empty()){
            long long tn = q.front(); q.pop();
            for(auto [nei, neiwt]: adjl[tn]){
                long long curw = (neiwt>md);
                if(dist[nei] > dist[tn] + curw){
                    dist[nei] = dist[tn] + curw;
                    q.push(nei);
                }
            }
        }

        return dist[tgt];
    }
    
    int minimumThreshold(int n, vector<vector<int>>& edges, int sorc, int tagt, int k) {
        adjl.resize(n, vector<pair<int, int>>());
        this->n = n;
        this->src = sorc;
        this->tgt = tagt;
        
        for(auto ed: edges){
            long long u = ed[0];
            long long v = ed[1];
            long long w = ed[2];
            adjl[u].push_back({v, w});
            adjl[v].push_back({u, w});
        }

        auto check = [&](long long md){
            return bfs(src, md);  
        };

        long long lo = 0;
        long long hi = 1e9;
        long long ans = -1;
        while(lo<=hi){
            long long mid = (lo+hi)/2;
            if(check(mid) <= k){
                ans = mid;
                hi = mid-1;
            }else{
                lo = mid+1;
            }
        }

        return ans;
    }
};