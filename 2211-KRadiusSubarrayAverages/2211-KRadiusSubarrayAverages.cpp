// Last updated: 6/11/2026, 11:24:02 AM
class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        long long n = nums.size();
        // if(k == 0) return nums;
        vector<long long> pref(n+1, 0);
        pref[0] = nums[0];
        for(long long i=1; i<n; i++){
            pref[i] = pref[i-1] + nums[i];
        }
        pref[n] = pref[n-1];

        vector<int> ans(n, -1);
        for(long long i=0; i<n; i++){
            long long r = i+k;
            long long l = i-k;
            if(r>=n || l<0){
                continue;
            }
            long long val = (pref[r] - ((l-1>=0)?pref[l-1]:0))/(2*k + 1);
            ans[i] = val;
        }

        return ans;
    }
};