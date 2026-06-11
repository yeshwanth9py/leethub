// Last updated: 6/11/2026, 11:11:00 AM
class Solution {
public:
    unordered_map<int, vector<int>> ump;
    vector<vector<int>> adjl;
    map<pair<int, int>, int> mp;
    vector<int> minimumFlips(int n, vector<vector<int>>& edges, string start, string target) {
        adjl.resize(n, vector<int>());
        int idx = 0;
        for(auto el: edges){
            int u = el[0];
            int v = el[1];
            adjl[u].push_back(v);
            adjl[v].push_back(u);
            mp[{min(u, v), max(u, v)}] = idx;
            idx++;
        }

        queue<int> q;
        vector<int> vis(n, 0);
        vector<int> par(n, -1);
        q.push(0);
        vis[0] = 1;
        int lvl = 0;
        while(!q.empty()){
            lvl++;
            int sz = q.size();
            for(int i=0; i<sz; i++){
                auto tn = q.front(); q.pop();
                ump[lvl].push_back(tn);
                for(int nei: adjl[tn]){
                    if(vis[nei] == 0){
                        vis[nei] = 1;
                        par[nei] = tn;
                        q.push(nei);
                    }
                }
            }
        }

        vector<int> mark(n, 0);
        for(int i=0; i<n; i++){
            if(start[i] != target[i]){
                mark[i] = 1;
            }
        }

        int maxl = lvl;
        int curl = maxl;
        vector<int> ans;
        while(curl>0){
            if(curl == 1){
                int nd = ump[curl][0];
                if(mark[nd] == 1) return {-1};
            }else{
                for(int nd: ump[curl]){
                    if(mark[nd] == 1){
                        mark[nd] = 0;
                        int pp = par[nd];
                        mark[pp] ^= 1;
                        int id = mp[{min(nd, pp), max(nd, pp)}];
                        ans.push_back(id);
                    }
                }
            }
            curl--;
        }
        sort(ans.begin(), ans.end());
        return ans;

    }
};