// Last updated: 6/11/2026, 11:09:42 AM
class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<int> ans(n, 0);
        for(int i=0; i<n; i++){
            int cnt = 0;
            for(int j=0; j<n; j++){
                if(mat[i][j] == 1) cnt++;
            }
            ans[i] = cnt;
        }
        return ans;
    }
};