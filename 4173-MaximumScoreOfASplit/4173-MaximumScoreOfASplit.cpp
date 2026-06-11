// Last updated: 6/11/2026, 11:11:11 AM
class Solution {
public:
    long long maximumScore(vector<int>& nums) {
        long long n = nums.size();
        vector<long long> sufmin(n, 1e18);
        vector<long long> prefsum(n, 0);
        
        for(long long i=n-2; i>=0; i--){
            sufmin[i] = min(sufmin[i+1], 1LL*nums[i+1]);
        }

        long long cs = 0;
        long long ans = -1e18;
        for(long long i=0; i<n; i++){
            cs += nums[i];
            long long curr = cs - sufmin[i];
            ans = max(ans, curr);
        }

        return ans;


    }
};