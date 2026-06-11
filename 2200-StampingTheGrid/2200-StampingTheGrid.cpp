// Last updated: 6/11/2026, 11:24:08 AM
class Solution {
public:
    bool possibleToStamp(vector<vector<int>>& arr, int h, int w) {
        int n = arr.size();
        int m = arr[0].size();
        
        vector<vector<int>> pref(n, vector<int>(m, 0));

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                pref[i][j] = arr[i][j] +  (i-1>=0?pref[i-1][j]:0) + (j-1>=0?pref[i][j-1]:0) - ((i-1>=0 && j-1>=0)?pref[i-1][j-1]:0);
            }
        }

        vector<vector<int>> diff(n, vector<int>(m, 0));

        for(int r1=0; r1<n; r1++){
            for(int c1=0; c1<m; c1++){
                int r2 = r1+h-1;
                int c2 = c1+w-1;
                if(r2<n && c2<m){
                    int ones = pref[r2][c2] - (r1-1>=0?pref[r1-1][c2]:0) - (c1-1>=0?pref[r2][c1-1]:0) + ((r1-1>=0 && c1-1>=0)?pref[r1-1][c1-1]:0);
                    if(ones == 0){
                        diff[r1][c1]++;
                        if(c2+1<m) diff[r1][c2+1]--;
                        if(r2+1<n) diff[r2+1][c1]--;
                        if(r2+1<n && c2+1<m) diff[r2+1][c2+1]++;
                    }
                }
            }
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                diff[i][j] = diff[i][j] +  (i-1>=0?diff[i-1][j]:0) + (j-1>=0?diff[i][j-1]:0) - ((i-1>=0 && j-1>=0)?diff[i-1][j-1]:0);
                if(arr[i][j] == 0 && diff[i][j]<=0) return 0;
            }
        }

        return 1;

    }
};