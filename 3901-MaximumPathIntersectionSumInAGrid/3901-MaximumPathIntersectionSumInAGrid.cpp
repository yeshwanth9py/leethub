// Last updated: 6/11/2026, 11:14:46 AM
class Solution {
public:
    int maxScore(vector<vector<int>>& arr) {
        int n = arr.size();
        int m = arr[0].size();

        int ans = -1e9;

        for(int i=0; i<n; i++){
            int cs = arr[i][0];
            for(int j=1; j<m; j++){
                cs += arr[i][j];
                cs = max(cs, arr[i][j]+arr[i][j-1]);
                ans = max(ans, cs);
            }
        }

        for(int j=0; j<m; j++){
            int cs = arr[0][j];
            for(int i=1; i<n; i++){
                cs += arr[i][j];
                cs = max(cs, arr[i][j]+arr[i-1][j]);
                ans = max(ans, cs);
            }
        }

        for(int i=1; i<n-1; i++){
            for(int j=1; j<m-1; j++){
                ans = max(ans, arr[i][j]);
            }
        }

        return ans;
    }
};