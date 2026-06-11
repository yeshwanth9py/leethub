// Last updated: 6/11/2026, 11:17:15 AM
class Solution {
public:
    vector<vector<int>> adjl2;
    vector<vector<int>> adjl1;
    int bfs(int node, int k, vector<vector<int>> &adjl){
        queue<pair<int, int>> q;
        q.push({node, 0});
        int neighbors = 0;
        int m = adjl.size();
        vector<int> vis(m+1, 0);
        vis[node] = 1;
        while(!q.empty()){
            int sz = q.size();
            if(q.front().second>k){
                break;
            }
            neighbors += sz;
            for(int i=0; i<sz; i++){
                auto tn = q.front(); q.pop();
                for(int nei: adjl[tn.first]){
                    if(vis[nei] == 0){
                        q.push({nei, tn.second+1});
                        vis[nei] = 1;
                    }
                }
            }
        }

        return neighbors;

    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int m = edges2.size();
        int n = edges1.size();

        adjl2.resize(m+1, vector<int>());
        adjl1.resize(n+1, vector<int>());

        for(auto edg: edges1){
            adjl1[edg[0]].push_back(edg[1]);
            adjl1[edg[1]].push_back(edg[0]);
        }


        for(auto edg: edges2){
            adjl2[edg[0]].push_back(edg[1]);
            adjl2[edg[1]].push_back(edg[0]);
        }

        int maxnei = 0;
        for(int i=0; i<=m; i++){
            maxnei = max(maxnei, bfs(i, k-1,adjl2));
        }

        vector<int> ans(n+1, 0);

        for(int i=0; i<=n; i++){
            int neis = bfs(i, k, adjl1);
            ans[i] = maxnei+neis;
        }


        return ans;

    }
};