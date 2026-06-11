// Last updated: 6/11/2026, 11:25:24 AM
class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& tar) {
        int n = mat.size();
        int m = mat[0].size();

        if(mat == tar) return 1;

        //right 90
        bool pos = 1;
        int ii = 0;
        int jj = m-1;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j] != tar[ii][jj]){
                    pos = 0;
                    break;
                }
                ii++;
            }
            if(pos == 0) break;
            ii = 0;
            jj = jj-1;
        }

        if(pos) return 1;

        ii = n-1;
        jj = m-1;
        pos = 1;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j] != tar[ii][jj]){
                    pos = 0;
                    break;
                }
                jj--;
            }
            if(pos == 0) break;
            jj = m-1;
            ii = ii-1;
        }

        if(pos) return 1;
        ii = n-1;
        jj = m-1;
        pos = 1;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j] != tar[ii][jj]){
                    pos = 0;
                    break;
                }
                jj--;
            }
            if(pos == 0) break;
            jj = m-1;
            ii = ii-1;
        }

        ii = n-1;
        jj = 0;
        pos = 1;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j] != tar[ii][jj]){
                    pos = 0;
                    break;
                }
                ii--;
            }
            if(pos == 0) break;
            jj = jj+1;
            ii = n-1;
        }

        return pos;
    }
};