// Last updated: 6/11/2026, 11:20:50 AM
class Solution {
public:
    int n;
    vector<int> vis;
    vector<vector<int>> adjl;
    vector<int> primefactor(int nb){
        vector<int> prim;

        for(int i=2; i*i<=nb; i++){
            if((nb%i) == 0){
                prim.push_back(i);
                while(nb%i == 0){
                    nb = nb/i;
                }
            }
        }

        if(nb>1){
            prim.push_back(nb);
        }

        return prim;
    }

    void dfs(int nd){
        vis[nd] = 1;
        for(int nei: adjl[nd]){
            if(vis[nei] == 0){
                dfs(nei);
            }
        }
    }

    bool canTraverseAllPairs(vector<int>& nums) {
        unordered_map<int, vector<int>> ump;
        n = nums.size();

        for(int i=0; i<nums.size(); i++){
            int nb = nums[i];
            vector<int> facts = primefactor(nb);
            for(int el: facts){
                ump[el].push_back(i);
            }
        }

        int tot = ump.size();
        adjl.resize(n, vector<int>());
        
        for(auto &el: ump){
            vector<int> &temp = el.second;
            for(int i=0; i<temp.size()-1; i++){
                int el1 = temp[i];
                int el2 = temp[i+1];
                adjl[el1].push_back(el2);
                adjl[el2].push_back(el1);
            }
        }

        vis.resize(n, 0);
        dfs(0); 

        for(int j=0; j<n; j++){
            if(vis[j] == 0) return 0;
        }

        return 1;

    }
};