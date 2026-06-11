// Last updated: 6/11/2026, 11:18:42 AM
class Dsu{
    public:
        vector<int> par;
        vector<int> rank;
        Dsu(int n){
            par.resize(n, 1);
            rank.resize(n, 1);
            for(int i=0; i<n; i++){
                par[i] = i;
            }
        }

        int find(int x){
            if(x == par[x]){
                return x;
            }
            return par[x] = find(par[x]);
        }

        void add(int x, int y){
            int px = find(x);
            int py = find(y);
            if(px == py){
                return;
            }
            if(rank[px]>=rank[py]){
                rank[py]+=rank[px];
                par[py] = px;
            }else{
                rank[px] += rank[py];
                par[px] = py;
            }
        }
};

void dfs(int node, vector<int> &vis, int &bitwise, vector<vector<pair<int, int>>> &adjl){
    vis[node] = 1;
    for(auto nei: adjl[node]){
        bitwise &= nei.second;
        if(vis[nei.first] == 0){
            dfs(nei.first, vis, bitwise, adjl);
        }
    }
}

class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        Dsu ds(n);
        vector<vector<pair<int, int>>> adjl(n+1, vector<pair<int, int>>());
        for(auto edg: edges){
            ds.add(edg[0], edg[1]);
            adjl[edg[0]].push_back({edg[1], edg[2]});
            adjl[edg[1]].push_back({edg[0], edg[2]});
        }

        vector<int> vis(n, 0);
        unordered_map<int, int> ump;
        for(int i=0; i<n; i++){
            int bitwise = 0;
            if(vis[i] == 0){
                if(adjl[i].size()==0){
                    bitwise = 0;
                    ump[i] = bitwise;
                    vis[i] = 1;
                    continue;
                }else{
                    bitwise = adjl[i][0].second;
                }
                dfs(i, vis, bitwise, adjl);
                int px = ds.find(i);
                ump[px] = bitwise;
            }
        }
        vector<int> ans;
        for(auto q: query){
            int x = q[0];
            int y = q[1];
            int px = ds.find(x);
            int py = ds.find(y);
            if(px != py){
                ans.push_back(-1);
            }else{
                ans.push_back(ump[px]);
            }
        }

        return ans;
    }
};