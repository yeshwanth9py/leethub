// Last updated: 6/11/2026, 11:31:05 AM
class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        queue<vector<int>> q;
        int n = graph.size();
        q.push({0});
        vector<vector<int>> ans;
        while(!q.empty()){
            vector<int> cv = q.front();
            q.pop();
            int ln = cv.back();
            if(ln == n-1){
                ans.push_back(cv);
                continue;
            }
            for(auto el: graph[ln]){
                vector<int> temp = cv;
                temp.push_back(el);
                q.push(temp);
            }
        }

        return ans;
    }
};