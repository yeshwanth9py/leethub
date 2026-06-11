// Last updated: 6/11/2026, 11:20:08 AM
class Solution {
public:
    vector<vector<pair<int, int>>> adjl;
    int indp[100100];
    int outdp[100100];
    void indfs(int node, int pp){
        indp[node] = 0;
        // int cost = 0;
        for(auto [nei, cos]: adjl[node]){
            if(nei != pp){
                indfs(nei, node);
                indp[node] += cos+indp[nei];
            }
        }
    }   

    void outdfs(int node, int pp, int ov){
        outdp[node] = ov;
        for(auto [nei, co]: adjl[node]){
            if(nei != pp){
                int fov = indp[node] - indp[nei] - (co);
                fov += (co == 0) + ov;
                outdfs(nei, node, fov);
            }
        }
    }

    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        adjl.resize(n, vector<pair<int, int>>());
        for(auto edg: edges){
            int u = edg[0];
            int v = edg[1];
            adjl[u].push_back({v, 0});
            adjl[v].push_back({u, 1});
        }

        indfs(0, -1);
        outdfs(0, -1, 0);

        vector<int> ans;
        for(int i=0; i<n; i++){
            ans.push_back(indp[i] + outdp[i]);
        }

        return ans;
    }
};