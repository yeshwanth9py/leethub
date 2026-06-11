// Last updated: 6/11/2026, 11:21:23 AM
int ans;
int dep[1000];
vector<vector<int>> conn;
class Solution {
public:
    void dfs(int cur, int par, int d) {
        dep[cur]=d;
        for(auto sub : conn[cur]) {
            if(sub!=par) {
                if(dep[sub]>d+1) {
                 // explore another path and it is possible to find a shorter cycle
                    dfs(sub, cur, d+1);
                } else if(dep[sub]<d){
                 // cycle detected
                    ans=min(ans, d-dep[sub]+1);
                }
            }
        }
    }

    int findShortestCycle(int n, vector<vector<int>>& edges) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        ans=INT_MAX;
        conn.clear();
        conn.resize(n);
        for(int i=0; i<n; dep[i++]=INT_MAX) {}
        for(int i=0, m=edges.size(); i<m; ++i) {
            conn[edges[i][0]].push_back(edges[i][1]);
            conn[edges[i][1]].push_back(edges[i][0]);
        }

        for(int i=0, j; i<n; ++i) {
            if(dep[i]==INT_MAX) // DFS on each connected sub-graph
                dfs(i, -1, 0);
        }

        return ans==INT_MAX? -1 : ans;

    }

};