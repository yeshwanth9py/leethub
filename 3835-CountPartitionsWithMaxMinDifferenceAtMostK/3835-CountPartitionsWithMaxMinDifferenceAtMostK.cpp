// Last updated: 6/11/2026, 11:15:18 AM
class Solution {
public:
    vector<int> arr;
    vector<int> validtill;
    int n;
    int mod = 1e9+7;
    int rec(){
        // if(ind == n) return 1;

        // if(dp[ind]!=-1) return dp[ind];
        // int ways = 0;
        // for(int i=ind; i<=validtill[ind]; i++){
        //     ways += rec(i+1);
        //     if(ways>=mod){
        //         ways -= mod;
        //     }
        // }

        // return dp[ind] = ways;
        vector<int> dp(n+1, 0);
        vector<int> suff(n+1, 0);
        dp[n] = 1;
        suff[n] = 1;
        for(int ind=n-1; ind>=0; ind--){
            int ways = 0;
            // for(int i=ind; i<=validtill[ind]; i++){
            //     ways += dp[i+1];
            //     if(ways>=mod){
            //         ways -= mod;
            //     }
            // }
            // dp[ind] = dp[ind+1] + dp[ind+2] + dp[ind+3] +....dp[r+1]; 
            int r = validtill[ind];
            dp[ind] = (suff[ind+1] - (r+2<=n?suff[r+2]:0) + mod)%mod;
            suff[ind] = (suff[ind+1]+dp[ind])%mod;
        }

        return dp[0];

    }

    int countPartitions(vector<int>& nums, int k) {
        n = nums.size();
        validtill.resize(n, -1);
        multiset<int> ms;
        int j = -1;
        int i = 0;
        // memset(dp, 0, sizeof(dp));

        int mintn = 1e9;
        int maxtn = -1e9;

        while(i<n){
            while(j+1<n && abs(min(nums[j+1], mintn) - max(nums[j+1], maxtn)) <= k  ){
                j++;
                ms.insert(nums[j]);
                mintn = *ms.begin();
                maxtn = *ms.rbegin();
            }

            validtill[i] = max(i, j);
            
            ms.erase(ms.find(nums[i]));
            if(ms.size()>0){
                mintn = *ms.begin();
                maxtn = *ms.rbegin();
            }else{
                mintn = 1e9;
                maxtn = -1e9;
            }
            i++;
        }

        int ans = rec();
        return ans;
    }
};