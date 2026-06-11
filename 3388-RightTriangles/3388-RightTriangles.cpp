// Last updated: 6/11/2026, 11:18:34 AM
class Solution {
public:
    long long numberOfRightTriangles(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> prefr(n, vector<int>(m, 0)); 
        vector<vector<int>> prefc(n, vector<int>(m, 0));

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                prefr[i][j] = ((j-1>=0)?prefr[i][j-1]:0);
                prefc[i][j] = ((i-1>=0)?prefc[i-1][j]:0);
                if(grid[i][j] == 1){
                    prefr[i][j] += 1;
                    prefc[i][j] += 1;
                }
            }
        }

        long long ans = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1){
                    long long top = prefc[i][j]-1;
                    long long bot = prefc[n-1][j] - prefc[i][j];
                    long long left = prefr[i][j] - 1;
                    long long right = prefr[i][m-1]-prefr[i][j];
                    long long curt = top*right + right*bot + bot*left + left*top;
                    ans += curt;
                }
            }
        }

        return ans;


    }
};