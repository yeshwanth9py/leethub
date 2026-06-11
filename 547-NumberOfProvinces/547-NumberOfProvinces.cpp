// Last updated: 6/11/2026, 11:32:34 AM
class Solution {
public:
    void dfs(int i, vector<int> &vis, vector<vector<int>>& isConnected){
        int n = isConnected.size();
        vis[i] = 1;
        for(int j=1; j<=n; j++){
            if(isConnected[i-1][j-1] == 1 && vis[j] == 0){
                vis[j] = 1;
                dfs(j, vis, isConnected);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> vis(n+1, 0);
        int tp = 0;
        for(int i=1; i<=n; i++){
            if(vis[i] == 0){
                tp++;
                dfs(i, vis, isConnected);
            }
        }
        return tp;
    }
};