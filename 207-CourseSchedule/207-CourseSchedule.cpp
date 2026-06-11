// Last updated: 6/11/2026, 11:34:53 AM
class Solution {
public:
    vector<vector<int>> adjl;
    bool canFinish(int n, vector<vector<int>>& pre) {
        adjl.resize(n, vector<int>());
        vector<int> indeg(n, 0);
        for(auto el: pre){
            int u = el[0];
            int v = el[1];
            adjl[v].push_back(u);
            indeg[u]++;
        }
        vector<int> vis(n, 0);
        queue<int> q;
        for(int i=0; i<n; i++){
            if(indeg[i] == 0){
                q.push(i);
                vis[i] = 1;
            }
        }

        while(!q.empty()){
            auto tn = q.front(); q.pop();
            for(int nei: adjl[tn]){
                indeg[nei]--;
                if(indeg[nei] == 0){
                    vis[nei] = 1;
                    q.push(nei);
                }
            }
        }

        for(int i=0; i<n; i++){
            if(vis[i] == 0) return 0;
        }
        return 1;

    }
};