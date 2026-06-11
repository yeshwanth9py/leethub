// Last updated: 6/11/2026, 11:23:57 AM
class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_set<string> sup(supplies.begin(), supplies.end());
        unordered_map<string, vector<string>> adjl;
        unordered_map<string, int> indegree;

        int n = recipes.size();

        for(int i=0; i<n; i++){
            indegree[recipes[i]] = 0;
            for(auto el: ingredients[i]){
                if(sup.find(el)==sup.end()){
                    adjl[el].push_back(recipes[i]);
                    indegree[recipes[i]]++;
                }
            }
        }

        queue<string> q;
        for(auto el: indegree){
            if(el.second == 0){
                q.push(el.first);
            }
        }

        vector<string> ans;

        while(!q.empty()){
            auto cn = q.front();
            q.pop();
            ans.push_back(cn);
            for(auto nei: adjl[cn]){
                indegree[nei]--;
                if(indegree[nei] == 0){
                    q.push(nei);
                }
            }
        }

        return ans;
    }
};















