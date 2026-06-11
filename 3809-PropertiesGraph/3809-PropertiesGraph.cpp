// Last updated: 6/11/2026, 11:15:35 AM
class Solution {
public:
    bool canintersect(int n1, int n2, unordered_map<int, int[101]> &ump, int k){
        int com = 0;
        for(int i=1; i<=100; i++){
            if(ump[n1][i]>0 && ump[n2][i]>0){
                com++;
            }
        }
        return com>=k;
    }
    void dfs(int node, vector<int> &vis, vector<vector<int>> &adjl){
        vis[node] = 1;
        for(int nei: adjl[node]){
            if(vis[nei] == 0){
                dfs(nei, vis, adjl);
            }
        }
    }
    int numberOfComponents(vector<vector<int>>& arr, int k) {
        unordered_map<int, int[101]> ump;
        int n = arr.size();
        for(int i=0; i<arr.size(); i++){
            for(int j=0; j<arr[i].size(); j++){
                ump[i][arr[i][j]]++;
            }
        }
        vector<vector<int>> adjl(n+1, vector<int>());
        for(int i=0; i<arr.size(); i++){
            for(int j=0; j<arr.size(); j++){
                if(canintersect(i, j, ump, k)){
                    adjl[i].push_back(j);
                    adjl[j].push_back(i);
                }
            }
        }

        int noc = 0;
        vector<int> vis(n+1, 0);
        for(int i=0; i<n; i++){
            if(vis[i] == 0){
                dfs(i, vis, adjl);
                noc++;
            }
        }
        return noc;
        
    }
};