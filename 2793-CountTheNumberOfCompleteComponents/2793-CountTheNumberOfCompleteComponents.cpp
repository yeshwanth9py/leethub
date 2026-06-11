// Last updated: 6/11/2026, 11:20:52 AM
class Solution {
public:
    vector<vector<int>> adjl;
    int dfs(int node, int col, vector<int> &vis){
        vis[node] = col;
        int sz = 1;
        for(int nei: adjl[node]){
            if(vis[nei] == 0){
                sz += dfs(nei, col, vis);
            }
        }
        return sz;
    }
    bool dfscheck(int node, vector<int> &sizes, vector<int> &mark){
        mark[node] = 1;
        int cs = sizes[node];
        cout<<node<<" "<<cs<<" "<<adjl[node].size()<<endl;
        int rv = 1;
        if(adjl[node].size() != cs-1){
            rv = 0;
        }
        for(int nei: adjl[node]){
            if(mark[nei] == 0){
                if(dfscheck(nei, sizes, mark) == 0){
                    rv = 0;
                }
            }
        }

        return rv;
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<int> vis(n+1, 0);
        vector<int> sizes(n+1, 1);
        adjl.clear();
        adjl.resize(n+1, vector<int>());
        for(auto edg: edges){
            adjl[edg[0]].push_back(edg[1]);
            adjl[edg[1]].push_back(edg[0]);
        }
        int color = 1;
        unordered_map<int, int> ump;
        for(int i=0; i<n; i++){
            if(vis[i] == 0){
                int sz = dfs(i, color, vis);
                ump[color] = sz;
                color++;
            }
        }

        for(int i=0; i<n; i++){
            sizes[i] = ump[vis[i]];
            // cout<<i<<"-"<<sizes[i]<<", ";
        }

        int compcomp = 0;
        vector<int> mark(n+1, 0);
        for(int i=0; i<n; i++){
            if(mark[i] == 0){
                if(dfscheck(i, sizes, mark)){
                    compcomp++;
                }
            }
        }

        return compcomp;
    }
};