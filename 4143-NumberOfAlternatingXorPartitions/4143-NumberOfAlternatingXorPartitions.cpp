// Last updated: 6/11/2026, 11:12:01 AM
class Solution {
public:
    int t1;
    int t2;
    vector<int> nums;
    int n;
    int dp[100100][2];
    const int mod = 1e9+7;
    int rec(){
        // int curx = 0;
        // int ans = 0;
        // for(int j=ind; j<n; j++){
        //     curx ^= nums[j];
        //     if((need == 0 && curx == t1) || (need==1 && curx==t2)){
        //         ans += rec(j+1, !need);
        //     }
        // }
        map<pair<int, int>, int> mp;
        int sufx = 0;
        for(int ind=n; ind>=0; ind--){
            if(ind<n) sufx ^= nums[ind];
            for(int need=0; need<=1; need++){
                if(ind == n){
                    dp[ind][need] = 1;
                    continue;
                }
                int ans = 0;
                
                // for(int j=ind; j<n; j++){
                //     curx ^= nums[j];
                //     if((need == 0 && curx == t1) || (need == 1 && curx == t2) ){
                //         ans += dp[j+1][!need];
                //     }
                // }
                int target = ((need==0)?t1:t2);
                int needs = sufx^target;
                ans += mp[{needs, !need}];

                dp[ind][need] = ans;
            }
            mp[{sufx, 0}] = ((mp[{sufx, 0}] + dp[ind][0])%mod + mod)%mod;
            mp[{sufx, 1}] = ((mp[{sufx, 1}] + dp[ind][1])%mod + mod)%mod;
        }


        return dp[0][0];
    }
    int alternatingXOR(vector<int>& nums, int target1, int target2) {
        this->nums = nums;
        t1 = target1;
        t2 = target2;
        n = nums.size();
        return rec();
    }
};