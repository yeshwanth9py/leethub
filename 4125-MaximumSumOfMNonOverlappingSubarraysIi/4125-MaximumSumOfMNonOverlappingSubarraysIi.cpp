// Last updated: 6/11/2026, 11:12:21 AM
class Solution {
public:
    long long maximumSum(vector<int>& nums, long long m, long long l, long long r) {
       long long n = nums.size();
       long long pro = -1e18;

        vector<long long> pref(n, 0);
        pref[0] = nums[0];
        for(long long i=1; i<n; i++){
            pref[i] = pref[i-1] + nums[i];
        }

        auto canieat2 = [&](long long i, long long j){
            if((i-1>=0?pref[i-1]:0)>=(j-1>=0?pref[j-1]:0)){
                return 1;
            }
            return 0;
        };

        deque<long long> dq;
        for(long long i=0; i<n; i++){
            long long l1 = i-r+1;
            long long l2 = i-l+1;
            if(l2>=0){
                while(!dq.empty() && canieat2(dq.back(), l2)){
                    dq.pop_back();
                }
                dq.push_back(l2);
                while(!dq.empty() && dq.front()<l1){
                    dq.pop_front();
                }
                long long ind = dq.front();
                pro = max(pro, pref[i]-(ind-1>=0?pref[ind-1]:0));
            }
        }
       
        
        if (pro <= 0) {
            return pro;
        }

        auto canieat = [&](long long i, long long j, vector<pair<long long, long long>> &dp){
            long long prevv = (i-1>=0?(dp[i-1].first - pref[i-1]):0);
            long long newv = (j-1>=0?(dp[j-1].first - pref[j-1]):0);

            long long prevc = (i-1>=0?(dp[i-1].second):0);
            long long newc = (j-1>=0?(dp[j-1].second):0);
            if(newv>prevv || (newv == prevv && newc<prevc)){
                return 1;
            }
            return 0;
        };

        auto check = [&](long long tax){
            vector<pair<long long, long long>> dp(n, {0, 0});
            deque<long long> dq;
            for(long long i=0; i<n; i++){
                if(i) dp[i] = dp[i-1];
                long long l1 = i-r+1;
                long long l2 = i-l+1;
                if(l2>=0){
                    while(!dq.empty() && canieat(dq.back(), l2, dp)){
                        dq.pop_back();
                    }

                    dq.push_back(l2);
                    while(!dq.empty() && dq.front()<l1){
                        dq.pop_front();
                    }

                    long long ind = dq.front();
                    long long curpro = (ind-1>=0?(dp[ind-1].first - pref[ind-1]):0)  + pref[i] - tax;
                    long long curcnt = (ind-1>=0?(dp[ind-1].second + 1):1);
                    if((curpro>dp[i].first) || (curpro == dp[i].first && curcnt<dp[i].second)){
                        dp[i] = {curpro, curcnt};
                    }
                }
            }
            return dp[n-1];
        };

        long long lo = 0;
        long long hi = 1e9;
        

        while(lo<=hi){
            long long mid = (lo+hi)/2;
            auto retv = check(mid);
            if(retv.second<=m){
                pro = retv.first + mid*m;
                hi = mid-1;
            }else{
                lo = mid+1;
            }
        }

        return pro;
    }
};