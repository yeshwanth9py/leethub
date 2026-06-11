// Last updated: 6/11/2026, 11:31:01 AM
class Solution {
public:
    vector<int> indeg;
    vector<vector<int>> adjl;
    int n;
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        n = graph.size();
        adjl.resize(n, vector<int>());
        indeg.resize(n, 0);


        for(int i=0; i<graph.size(); i++){
            for(int nei: graph[i]){
                indeg[i]++;
                adjl[nei].push_back(i);
            }
        }

        queue<int> q;

        for(int i=0; i<n; i++){
            if(indeg[i] == 0){
                q.push(i);
            }
        }

        vector<int> ans;
        while(!q.empty()){
            auto tel = q.front(); q.pop();
            ans.push_back(tel);
            for(int nei: adjl[tel]){
                indeg[nei]--;
                if(indeg[nei] == 0){
                    q.push(nei);
                }
            }
        }

        sort(ans.begin(), ans.end());

        return ans;

    }
};