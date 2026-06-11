// Last updated: 6/11/2026, 11:29:30 AM
class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& arr, int tar) {
        int n = arr.size();
        int m = arr[0].size();
        int ans = 0;

        for(int r1=0; r1<n; r1++){
            vector<int> val(m, 0);
            for(int r2=r1; r2<n; r2++){
                int sm = 0;
                unordered_map<int, int> ump;
                ump[0] = 1;
                for(int j=0; j<m; j++){
                    val[j] += arr[r2][j];
                    sm += val[j];
                    if(ump.find(sm-tar) != ump.end()){
                        ans += ump[sm-tar];
                    }
                    ump[sm]++;
                }
            }
        }

        return ans;

    }
};