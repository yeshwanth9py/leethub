// Last updated: 6/11/2026, 11:25:35 AM
class Solution {
public:
    vector<vector<int>> dp;
    vector<int> vis;
    vector<vector<int>> adjl;
    string colors;
    bool has_cycle = 0;
    void dfs(int node){
        vis[node] = 1;
        for(auto nei: adjl[node]){
            if(vis[nei] == 1){
                has_cycle = 1;
                return;
            }else if(vis[nei] == 0){
                dfs(nei);
                if(has_cycle){
                    return;
                }
                for(int i=0; i<26; i++){
                    dp[node][i] = max(dp[node][i], dp[nei][i]);
                }
            }else{
                for(int i=0; i<26; i++){
                    dp[node][i] = max(dp[node][i], dp[nei][i]);
                }
            }
        }
        dp[node][colors[node]-'a']++;
        vis[node] = 2;
    }


    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        dp.resize(n, vector<int>(26, 0));
        vis.resize(n, 0);  //0 1 2
        this->colors = colors;
        adjl.resize(n, vector<int>());
        for(auto edg: edges){
            adjl[edg[0]].push_back(edg[1]);
        }

        int maxlen = 0;
        for(int i=0; i<n; i++){
            if(vis[i] == 0){
                dfs(i);
                if(has_cycle){
                    return -1;
                }
            }
        }

        for(int i=0; i<n; i++){
            for(int col=0; col<26; col++){
                maxlen = max(maxlen, dp[i][col]);
            }
        }

        return maxlen;

    }
};