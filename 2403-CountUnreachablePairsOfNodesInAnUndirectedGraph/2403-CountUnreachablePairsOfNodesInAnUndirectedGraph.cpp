// Last updated: 6/11/2026, 11:22:51 AM
using ll = long long;
class Solution {
public:
    long long dfs(int cn, vector<vector<int>> &adjl, vector<int> &vis){
        vis[cn] = 1;
        long long ts = 1;
        for(auto el: adjl[cn]){
            if(vis[el] == 0){
                ts += dfs(el, adjl, vis);
            }
        }
        return ts;
    }

    long long countPairs(int n, vector<vector<int>>& edges) {
        long long mod = 1e9+7;
        vector<vector<int>> adjl(n, vector<int>());
        for(auto ed: edges){
            adjl[ed[0]].push_back(ed[1]);
            adjl[ed[1]].push_back(ed[0]);
        }

        vector<int> vis(n, 0);
        vector<long long> sizes;
        long long ans = 0;
        for(int i=0; i<n; i++){
            if(vis[i] == 0){
                sizes.push_back(dfs(i, adjl, vis));
            }
        }


        long long tot_pairs = (1ll*n*(n-1))/2;
        for(int i=0; i<sizes.size(); i++){
            long long cs = sizes[i];
            tot_pairs -= ((1ll*cs*(cs-1))/2);
        }
        
        return tot_pairs;


    }
};