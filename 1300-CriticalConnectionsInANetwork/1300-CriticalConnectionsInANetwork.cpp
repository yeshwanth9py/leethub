// Last updated: 6/11/2026, 11:28:59 AM
class Solution {
public:
    vector<int> vis;
    vector<vector<int>> adjl;
    vector<int> minin;
    vector<int> in;
    int time;
    vector<vector<int>> ans;

    void dfs(int node, int par){
        time++;
        vis[node] = 1;
        in[node] = time;
        minin[node] = time;
        for(int nei: adjl[node]){
            if(nei == par) continue;
            if(vis[nei] != 0){
                minin[node] = min(minin[nei], minin[node]);
            }else{
                dfs(nei, node);
                if(in[node] < minin[nei]){
                    ans.push_back({node, nei});
                }
                minin[node] = min(minin[nei], minin[node]);
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vis.clear();
        adjl.clear();
        minin.clear();
        in.clear();
        time = 0;
        vis.resize(n, 0);
        adjl.resize(n, vector<int>());
        minin.resize(n, 0);
        in.resize(n, 0);

        for(auto edg: connections){
            adjl[edg[0]].push_back(edg[1]);
            adjl[edg[1]].push_back(edg[0]);
        }


        for(int i=0; i<n; i++){
            if(vis[i] == 0){
                dfs(i, -1);
            }
        }

        return ans;
    }
};