// Last updated: 6/11/2026, 11:24:53 AM
class Solution {
public:
    bool dfs(int s, int d, vector<int> &vis, vector<vector<int>> &adjl){
        vis[s] = 1;
        if(s == d){
            return true;
        }
        for(auto el: adjl[s]){
            if(vis[el] == 0){
                if(dfs(el, d, vis, adjl)){
                    return true;
                }
            }
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adjl(n, vector<int>());
        for(auto edg: edges){
            adjl[edg[0]].push_back(edg[1]);
            adjl[edg[1]].push_back(edg[0]);
        }
        vector<int> vis(n, 0);
        return dfs(source, destination, vis, adjl);



    }
};