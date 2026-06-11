// Last updated: 6/11/2026, 11:14:43 AM
class Solution {
public:
    long long maxProduct(vector<int>& nums) {
        int mxel = *(max_element(nums.begin(), nums.end()));
        int len = log2(mxel);
        long long maxn = (1LL<<(len+1))-1;
        vector<long long> dp(maxn+1, 0);
        for(int el: nums){
            dp[el] = el;
        }

        for(int b=0; b<21; b++){
            for(int mask=0; mask<=maxn; mask++){
                if((mask & (1LL<<b))){
                    dp[mask] = max(dp[mask], dp[mask^(1LL<<b)]);
                }
            }
        }

        long long ans = 0;
        for(int el: nums){
            // cout<<((el^maxn))<<endl;
            ans = max(ans, el*dp[el^(maxn)]);
        }

        return ans;

    }
};