// Last updated: 6/11/2026, 11:29:14 AM
class Solution {
public:
    vector<vector<int>> adjlr;
    vector<vector<int>> adjlb;
    int dist[101][2];
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red, vector<vector<int>>& blu) {
        adjlr.resize(n, vector<int>());
        adjlb.resize(n, vector<int>());
        for(auto vel: red){
            int u = vel[0];
            int v = vel[1];
            adjlr[u].push_back(v);
        }

        for(auto vel: blu){
            int u = vel[0];
            int v = vel[1];
            adjlb[u].push_back(v);
        }


        for(int i=0; i<=n; i++){
            dist[i][0] = 1e9;
            dist[i][1] = 1e9;
        }

        queue<pair<int, int>> q;  //0 - red, 1 - blue
        q.push({0, 0});
        q.push({0, 1});
        dist[0][0] = dist[0][1] = 0;
        while(!q.empty()){
            auto [cur, col] = q.front(); q.pop();
            if(col == 0){
                for(int nei: adjlb[cur]){
                    if(dist[nei][1]>dist[cur][0]+1){
                        dist[nei][1]=dist[cur][0]+1;
                        q.push({nei, 1});
                    }
                }
            }else{
                for(int nei: adjlr[cur]){
                    if(dist[nei][0]>dist[cur][1]+1){
                        dist[nei][0]=dist[cur][1]+1;
                        q.push({nei, 0});
                    }
                }
            }
        }

        vector<int> ans;
        for(int i=0; i<n; i++){
            int curans = min(dist[i][0], dist[i][1]);
            if(curans == 1e9){
                ans.push_back(-1);
            }else{
                ans.push_back(curans);
            }
        }

        return ans;

    }
};