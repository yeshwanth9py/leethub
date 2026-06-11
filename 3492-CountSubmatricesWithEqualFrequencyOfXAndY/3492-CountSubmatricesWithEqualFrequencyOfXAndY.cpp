// Last updated: 6/11/2026, 11:17:55 AM
class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> pref(n, vector<int>(m, 0));
        vector<vector<int>> prefx(n, vector<int>(m, 0));

        int ans = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                int v = 0;
                int vx = 0;
                if(grid[i][j] == 'X'){
                    v = 1;
                    vx = 1;
                }else if(grid[i][j] == 'Y'){
                    v = -1;
                }

                pref[i][j] = v + (i-1>=0?pref[i-1][j]:0) + (j-1>=0?pref[i][j-1]:0) - ((i-1>=0 && j-1>=0)?pref[i-1][j-1]:0);
                prefx[i][j] = vx + (i-1>=0?prefx[i-1][j]:0) + (j-1>=0?prefx[i][j-1]:0) - ((i-1>=0 && j-1>=0)?prefx[i-1][j-1]:0);
                if(pref[i][j] == 0 && prefx[i][j]>0){
                    ans++;
                }
            }
        }

        return ans;
    }
};