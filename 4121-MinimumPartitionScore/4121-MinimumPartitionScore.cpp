// Last updated: 6/11/2026, 11:12:27 AM
class Solution {
public:
    long long minPartitionScore(vector<int>& nums, int k) {
        int n = nums.size();

        long long lo = -5e13;
        long long hi = 5e13;
        long long ans = 1e18; // MINIMAL FIX 1: Widen initial ans from 1e9

        vector<long long> pref(n, 0);
        pref[0] = nums[0];
        for(int i=1; i<n; i++){
            pref[i] = pref[i-1] + nums[i];
        }

        // MINIMAL FIX 2: Move vector allocation outside the binary search
        vector<pair<long long, long long>> dp(n); 

        auto check = [&](long long tax){
            // Reset DP array in O(N) instead of reallocating
            for(int i=0; i<n; i++) dp[i] = {1e18, 0}; 

            for(int i=0; i<n; i++){
                long long pi = pref[i]; // Cache prefix

                // MINIMAL FIX 3: Manually handle the j=0 case to eliminate all ternary operators
                long long sm0 = pi;
                dp[i] = {sm0 * (sm0 + 1) / 2 + tax, 1};

                // Now run j from i down to 1 cleanly
                for(int j=i; j>0; j--){
                    long long sm = pi - pref[j-1];
                    long long cost = sm * (sm + 1) / 2;
                    
                    long long cursc = dp[j-1].first + cost + tax;
                    long long curcnt = dp[j-1].second + 1;
                    
                    if(cursc < dp[i].first || (cursc == dp[i].first && curcnt < dp[i].second)){
                        dp[i] = {cursc, curcnt};
                    }
                }
            }
            return dp[n-1];
        };

        while(lo<=hi){
            // MINIMAL FIX 4: Prevent C++ negative truncation bugs
            long long mid = lo + (hi - lo) / 2; 
            auto retv = check(mid);
            if(retv.second<=k){
                ans = retv.first - 1LL*k*mid;
                hi = mid-1;
            }else{
                lo = mid+1;
            }
        }

        return ans;
    }
};