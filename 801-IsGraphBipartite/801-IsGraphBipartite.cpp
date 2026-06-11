// Last updated: 6/11/2026, 11:31:14 AM
class Solution {
public:
    bool dfs(int cn, int col, vector<int> &vis, vector<vector<int>>& graph){
        vis[cn] = col;
        for(auto el: graph[cn]){
            if(vis[el] == 0){
                if(dfs(el, col^1, vis, graph) == false){
                    return false;
                }
            }else if(vis[el] == col){
                return false;
            }
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n,0);
        for(int i=0; i<n; i++){
            if(vis[i]==0){
                if(!dfs(i, 0, vis, graph)){
                    return false;
                }
            }
        }

        return true;
    }
};