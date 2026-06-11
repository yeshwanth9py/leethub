// Last updated: 6/11/2026, 11:32:54 AM
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> all(n+m-1, vector<int>());

        for(int i=0; i<n; i++){
            for(int j = 0; j<m; j++){
                int ind = i+j;
                cout<<ind<<" ";
                all[ind].push_back(mat[i][j]);
            }
        }

        vector<int> ans;

        bool f = 0;
        for(auto vec: all){
            if(f==0){
                reverse(vec.begin(), vec.end());
            }
            for(int el: vec){
                ans.push_back(el);
            }
            f = !f;
        }

        return ans;


    }
};