// Last updated: 6/11/2026, 11:19:23 AM
class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> matt(n, vector<int>(m, 0));
        for(int i=0; i<n; i++){
            if(i%2 == 0){
                int shi = k%m;
                int cj = 0;
                for(int j=shi; j<m; j++){
                    matt[i][cj] = mat[i][j];
                    if(matt[i][cj] != mat[i][cj]) return 0;
                    cj++;
                }
                for(int j=0; j<shi; j++){
                    matt[i][cj] = mat[i][j];
                    if(matt[i][cj] != mat[i][cj]) return 0;
                    cj++;
                }
            }else{
                int shi = k%m;
                int lp = m-shi;
                int cj = 0;
                for(int j=lp; j<m; j++){
                    matt[i][cj] = mat[i][j];
                     if(matt[i][cj] != mat[i][cj]) return 0;
                    cj++;
                }
                for(int j=0; j<lp; j++){
                    matt[i][cj] = mat[i][j];
                     if(matt[i][cj] != mat[i][cj]) return 0;
                    cj++;
                }
            }
        }

        return 1;
    }
};