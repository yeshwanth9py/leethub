// Last updated: 6/11/2026, 11:33:35 AM
class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& arr, int k) {
        int n = arr.size();
        int m = arr[0].size();
        int ans = -1e9;
        for(int r1=0; r1<n; r1++){
            vector<int> temp(m, 0);
            for(int r2=r1; r2<n; r2++){
                multiset<int> ms;
                int ss = 0;
                ms.insert(0);
                for(int c=0; c<m; c++){
                    temp[c] += arr[r2][c];
                    ss += temp[c];
                    auto it = ms.lower_bound(ss-k);
                    if (it != ms.end()) {
                        ans = max(ans, ss - (*it));
                    }
                    ms.insert(ss);
                }
            }
        }

        return ans;
    }
};





