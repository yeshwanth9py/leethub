// Last updated: 6/11/2026, 11:28:23 AM
class Solution {
public:
    int m;
    int n;
    vector<vector<int>> pref;
    bool check(int sl, vector<vector<int>> &mat, int th){
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                int r1 = i;
                int c1 = j;
                if(r1+sl-1<n && c1+sl-1<m){
                    int r2 = r1+sl-1;
                    int c2 = c1+sl-1;
                    int curs = pref[r2][c2] - ((r1-1>=0)?pref[r1-1][c2]:0) - ((c1-1>=0)?pref[r2][c1-1]:0) + ((r1-1>=0 && c1-1>=0)?pref[r1-1][c1-1]:0);
                    if(curs<=th) return 1;
                }
            }
        }

        return 0;
    }

    int maxSideLength(vector<vector<int>>& mat, int th) {
        n = mat.size();
        m = mat[0].size();
        pref.resize(n, vector<int>(m, 0));

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                pref[i][j] = (i-1>=0?pref[i-1][j]:0) + (j-1>=0?pref[i][j-1]:0) - ((i-1>=0 && j-1>=0)?pref[i-1][j-1]:0) + mat[i][j];
            }
        }

        int sl = min(m, n);
        while(sl>=1){
            if(check(sl, mat, th)){
                return sl;
            }
            sl--;
        }

        return 0;
    }
};