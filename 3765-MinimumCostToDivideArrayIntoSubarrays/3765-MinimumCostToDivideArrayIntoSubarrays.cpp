// Last updated: 6/11/2026, 11:16:10 AM
using ll = long long;
class Solution {
public:
    const ll INF = 1e18;
    
    long long minimumCost(vector<int>& nums, vector<int>& cost, int k) {
        int n = nums.size();
        
        vector<ll> prefixNum(n), prefixCost(n);
        prefixNum[0] = nums[0];
        prefixCost[0] = cost[0];
        for (int i = 1; i < n; i++){
            prefixNum[i] = prefixNum[i-1] + nums[i];
            prefixCost[i] = prefixCost[i-1] + cost[i];
        }
        
       
        auto segCost = [&](int j, int i, int p) -> ll {
            ll numPart = prefixNum[i-1] + (ll) k * p;
            ll costPart = prefixCost[i-1] - (j > 0 ? prefixCost[j-1] : 0);
            return numPart * costPart;
        };
        
        
        int maxSeg = n;
        
        vector<vector<ll>> dp(maxSeg+1, vector<ll>(n+1, INF));
        dp[0][0] = 0;
        
        
        function<void(int, int, int, int, int)> compute = [&](int p, int l, int r, int optL, int optR) {
            if(l > r) return;
            int mid = (l + r) / 2;
            int best = optL;
            dp[p][mid] = INF;
           
            for (int j = optL; j <= min(optR, mid-1); j++){
                ll cur = dp[p-1][j] + segCost(j, mid, p);
                if (cur < dp[p][mid]) {
                    dp[p][mid] = cur;
                    best = j;
                }
            }
            compute(p, l, mid-1, optL, best);
            compute(p, mid+1, r, best, optR);
        };
        
        
        for (int p = 1; p <= maxSeg; p++){
            compute(p, p, n, p-1, n);
        }
        
        
        ll ans = INF;
        for (int p = 1; p <= maxSeg; p++){
            ans = min(ans, dp[p][n]);
        }
        return ans;
    }
};
