// Last updated: 6/11/2026, 11:12:34 AM
struct Unionfind{
    vector<int> par;
    vector<int> sz;
    vector<int> wt;
    Unionfind(int n){
        par.resize(n, -1);
        sz.resize(n, 1);
        wt.resize(n, 0);
        for(int i=0; i<n; i++) par[i] = i;
    }
    
    pair<int, int> find(int u){
        if(u == par[u]){
            return {0, u};
        }
        auto [pw, pr] = find(par[u]);
        wt[u] = wt[u]+pw;
        par[u] = pr;
        return {wt[u], par[u]};
    }

    bool merge(int u, int v, int weit){
        auto [wu, pu] = find(u);
        auto [wv, pv] = find(v);
        if(pu == pv){
            if((wu+wv+weit)%2 == 0){
                return 1;
            }else{
                return 0;
            }
        }else{
            if(sz[pv]>sz[pu]) swap(pu, pv);
            sz[pu] += sz[pv];
            par[pv] = pu;
            wt[pv] = (weit+wu+wv)%2;
            return 1;
        }
    }
};


class Solution {
public:
    int numberOfEdgesAdded(int n, vector<vector<int>>& edges) {
        Unionfind uf(n);
        int ans = 0;
        for(auto edg: edges){
            int u = edg[0];
            int v = edg[1];
            int wt = edg[2];
            if(uf.merge(u, v, wt)){
                ans++;
            }
        }

        return ans;
    }
};