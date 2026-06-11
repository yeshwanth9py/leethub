// Last updated: 6/11/2026, 11:28:27 AM
class Solution {
public:
    int countSquares(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int cnt = 0;
        vector<vector<int>> pref(n, vector<int>(m, 0));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(i==0 || j==0){
                    pref[i][j] = mat[i][j];
                    if(pref[i][j] == 1) cnt++;
                }else{
                    if(mat[i][j] == 0) continue;
                    pref[i][j] = 1+min({pref[i-1][j], pref[i][j-1], pref[i-1][j-1]});
                    cnt += pref[i][j];
                }
            }
        }

        return cnt;
    }
};