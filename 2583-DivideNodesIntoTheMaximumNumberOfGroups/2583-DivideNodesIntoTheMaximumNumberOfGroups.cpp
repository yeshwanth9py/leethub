// Last updated: 6/11/2026, 11:21:48 AM
class Solution {
public:
    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjl(n, vector<int>());
        for(auto el: edges){
            int u = el[0];
            int v = el[1];
            u--;
            v--;
            adjl[u].push_back(v);
            adjl[v].push_back(u);
        }
        
        vector<int> vis(n, -1);

        vector<vector<int>> all;
        for(int i=0; i<n; i++){
            if(vis[i] == -1){
                queue<int> q;
                q.push(i);
                vis[i] = 0;
                vector<int> temp;
                while(!q.empty()){
                    auto tn = q.front(); q.pop();
                    temp.push_back(tn);
                    for(int nei: adjl[tn]){
                        if(vis[nei] == -1){
                            vis[nei] = (vis[tn]^1);
                            q.push(nei);
                        }else if(vis[nei] == vis[tn]){
                            return -1;
                        }
                    }
                }
                all.push_back(temp);
            }
        }

        int tot = 0;
        for(auto vec:all){
            int maxgs = 1;
            for(int i: vec){
                vector<int> dist(n, -1);
                dist[i] = 1;
                queue<int> q;
                q.push(i);
                while(!q.empty()){
                    auto tn = q.front(); q.pop();
                    for(int nei: adjl[tn]){
                        if(dist[nei] == -1){
                            dist[nei] = dist[tn]+1;
                            maxgs = max(maxgs, dist[nei]);
                            q.push(nei);
                        }
                    }
                }
            }

            tot += maxgs;
        }

        return tot;

    }
};