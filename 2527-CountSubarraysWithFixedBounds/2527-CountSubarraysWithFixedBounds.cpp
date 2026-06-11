// Last updated: 6/11/2026, 11:22:05 AM
class Solution {
public:
    long long countSubarrays(vector<int>& arr, int mn, int mx) {
        long long n = arr.size();
        long long linv = -1;
        long long lmn = -1;
        long long lmx = -1;
        long long ans = 0;
        for(long long i=0; i<n; i++){
            if(arr[i]<mn || arr[i]>mx){
                linv = i;
            }
            if(arr[i] == mn){
                lmn = i;
            }

            if(arr[i] == mx){
                lmx = i;
            }

            if(linv<min(lmn, lmx)){
                long long cur = min(lmn, lmx);
                ans += (cur-linv);
            }
        }

        return ans;
    }
};