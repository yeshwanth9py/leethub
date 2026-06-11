// Last updated: 6/11/2026, 11:22:38 AM
class Solution {
public:
    int n;
    vector<int> edg;
    vector<int> vis;
    int ans;
    void dfs(int node, unordered_map<int, int> &ump, int num){
        vis[node] = 1;
        int nei = edg[node];
        if(nei == -1) return;
        ump[node] = num;
        if(vis[nei] == 0){
            dfs(nei, ump, num+1);
        }else{
            if(ump.find(nei) != ump.end()){
                int cur = num - ump[nei];
                ans = max(ans, cur);
            }
        }
    }

    int longestCycle(vector<int>& edg) {
        n = edg.size();
        this->edg = edg;
        ans = 0;
        vis.resize(n, 0);

        for(int i=0; i<n; i++){
            if(vis[i] == 0){
                unordered_map<int, int> ump;
                dfs(i, ump, 1);
            }
        }

        if(ans == 0) return -1;

        return ans+1;
    }
};