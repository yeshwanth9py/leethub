// Last updated: 6/11/2026, 11:13:09 AM
class Solution {
public:
    vector<vector<string>> wordSquares(vector<string>& words) {
        int n = words.size();
        vector<vector<string>> ans;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                for(int k=0; k<n; k++){
                    for(int l=0; l<n; l++){
                        set<int> allpo = {i, j, k, l};
                        if(allpo.size()<4) continue;
                        string top = words[i];
                        string left = words[j];
                        string right = words[k];
                        string bot = words[l];
                        if(top[0] == left[0] && top[3] == right[0] && bot[0] == left[3] && bot[3] == right[3]){
                            // vector<
                            ans.push_back({top, left, right, bot});
                        }
                    }
                }
            }
        }

        sort(ans.begin(), ans.end());

        return ans;

        
    }
};