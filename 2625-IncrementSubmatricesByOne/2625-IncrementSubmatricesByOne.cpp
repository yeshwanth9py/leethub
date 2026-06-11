// Last updated: 6/11/2026, 11:21:36 AM
class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& q) {
        vector<vector<int>> arr(n, vector<int>(n, 0));
        for(auto el: q){
            int r1 = el[0];
            int c1 = el[1];
            int r2 = el[2];
            int c2 = el[3];
            arr[r1][c1] += 1;
            if(c2+1<n) arr[r1][c2+1] -= 1;
            if(r2+1<n) arr[r2+1][c1] -= 1;
            if(r2+1<n && c2+1<n) arr[r2+1][c2+1] += 1;
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                arr[i][j] += (i-1>=0?arr[i-1][j]:0) + (j-1>=0?arr[i][j-1]:0) - ((i-1>=0 && j-1>=0)?arr[i-1][j-1]:0);
            }   
        }

        return arr;



    }
};