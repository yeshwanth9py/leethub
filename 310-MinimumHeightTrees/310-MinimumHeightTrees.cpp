// Last updated: 6/11/2026, 11:33:52 AM
class Solution {
public:
    int indp[20011];
    int outdp[20011];
    vector<vector<int>> adjl;

    void indfs(int node, int pp){
        indp[node] = 0;
        for(int nei: adjl[node]){
            if(nei != pp){
                indfs(nei, node);
                indp[node] = max(indp[node], indp[nei]+1);
            }
        }
    }

    void outdfs(int node, int pp, int outv){
        outdp[node] = outv;

        int mx1 = -1e9;
        int mx2 = -1e9;
        for(int nei: adjl[node]){
            if(nei != pp){
                if(indp[nei]>=mx1){
                    mx2 = mx1;
                    mx1 = indp[nei];
                }else if(indp[nei]>=mx2){
                    mx2 = indp[nei];
                }
            }
        }

        for(int nei: adjl[node]){
            if(nei != pp){  
                int v1 = 0;
                if(mx1 == indp[nei]){
                    v1 = mx2;
                }else{
                    v1 = mx1;
                }
                outdfs(nei, node, max(outdp[node]+1, v1+2));
            }
        }

    }   

    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        adjl.resize(n, vector<int>());
        for(auto edg: edges){
            int u = edg[0];
            int v = edg[1];
            adjl[u].push_back(v);
            adjl[v].push_back(u);
        }

        indfs(0, -1);
        outdfs(0, -1, 0);

        vector<pair<int, int>> ans;
        for(int i=0; i<n; i++){
            int cv = max(outdp[i], indp[i]);
            ans.push_back({cv, i});
        }

        sort(ans.begin(), ans.end());

        vector<int> retans;
        retans.push_back(ans[0].second);
        int smv = ans[0].first;
        for(int i=1; i<n; i++){
            if(smv == ans[i].first){
                retans.push_back(ans[i].second);
            }
        }

        return retans;

        
    }
};