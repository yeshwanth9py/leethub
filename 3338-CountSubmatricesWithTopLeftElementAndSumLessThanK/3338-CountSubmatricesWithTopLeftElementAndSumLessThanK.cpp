// Last updated: 6/11/2026, 11:18:43 AM
class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> pref(n, vector<int>(m, 0));
        int ans = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                pref[i][j] = grid[i][j];
                pref[i][j] += (i-1>=0?pref[i-1][j]:0) + (j-1>=0?pref[i][j-1]:0) - ((i-1>=0 && j-1>=0)?pref[i-1][j-1]:0);
                if(pref[i][j] <= k){
                    ans++;
                }
            }
        }

        return ans;
    }
};