// Last updated: 6/11/2026, 11:15:11 AM
class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& arr) {
        int n = arr.size();
        int m = arr[0].size();
        long long ts = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                ts += arr[i][j];
            }
        }
        if(ts%2!=0) return 0;

        long long hs = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                hs += arr[i][j];
                if(hs == ts/2) return 1;
            }
        }

        long long vs = 0;
        for(int j=0; j<m; j++){
            for(int i=0; i<n; i++){
                vs += arr[i][j];
                if(vs == ts/2) return 1;
            }
        }

        return 0;
        
    }
};