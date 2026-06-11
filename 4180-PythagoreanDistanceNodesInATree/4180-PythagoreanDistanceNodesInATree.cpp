// Last updated: 6/11/2026, 11:11:01 AM

#define ll long long

class Solution {
public:
    vector<vector<ll>> adjl;
    ll distx[200100];
    ll disty[200100];
    ll distz[200100];

    void dfs1(ll node, ll pp, ll dd){
        distx[node] = dd;
        for(ll nei: adjl[node]){
            if(nei != pp){
                dfs1(nei, node, dd+1);
            }
        }
    }
    void dfs2(ll node, ll pp, ll dd){
        disty[node] = dd;
        for(ll nei: adjl[node]){
            if(nei != pp){
                dfs2(nei, node, dd+1);
            }
        }
    }
    
    void dfs3(ll node, ll pp, ll dd){
        distz[node] = dd;
        for(ll nei: adjl[node]){
            if(nei != pp){
                dfs3(nei, node, dd+1);
            }
        }
    }

    
    int specialNodes(int n, vector<vector<int>>& edges, int x, int y, int z) {
        adjl.resize(n, vector<ll>());
        for(auto ed: edges){
            ll u = ed[0];
            ll v = ed[1];
            adjl[u].push_back(v);
            adjl[v].push_back(u);
        }

        distx[x] = 0;
        dfs1(x, -1, 0);
        dfs2(y, -1, 0);
        dfs3(z, -1, 0);

        ll ans = 0;
        for(ll i=0; i<n; i++){
            ll dx = distx[i];
            ll dy = disty[i];
            ll dz = distz[i];
            if(dx>=dy && dx>=dz){
                swap(dx, dz);
            }
            if(dy>=dx && dy>=dz){
                swap(dy, dz);
            }
            if((dx*dx) + (dy*dy) == dz*dz){
                ans++;
            }
        }

        return ans;

        
    }
};