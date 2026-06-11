// Last updated: 6/11/2026, 11:34:49 AM
class Solution {
public:
    bool dfs(int nd, vector<vector<int>> &adjl, vector<int> &vis, vector<int> &ans){
        vis[nd] = 1;
        for(auto el: adjl[nd]){
            if(vis[el] == 0){
                if(dfs(el, adjl, vis, ans) == false){
                    return false;
                }
            }else if(vis[el] == 1){
                return false;
            }
        }

        vis[nd] = 2;
        ans.push_back(nd);
        return true;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int>> adjl(n, vector<int>());
        for(auto pr: prerequisites){
            adjl[pr[0]].push_back(pr[1]);
        }
        vector<int> vis(n, 0);
        vector<int> ans;
        for(int i=0; i<n; i++){
            if(vis[i] == 0){
                if(dfs(i, adjl, vis, ans)==false){
                    return {};
                }
            }
        }

        return ans;
    }
};