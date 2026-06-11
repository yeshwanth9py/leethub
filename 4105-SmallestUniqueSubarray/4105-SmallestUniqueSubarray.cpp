// Last updated: 6/11/2026, 11:12:39 AM
class Solution {
public:
    long long mod = 1e9+7;
    
    long long binpow(long long x, long long n){
        if(n == 0) return 1;
        long long ans = binpow(x, n/2);
        ans = ((ans*ans)%mod + mod)%mod;
        if(n&1){
            ans = ((ans*x)%mod + mod)%mod;
        }
        return ans;
    }
    
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int lo = 1;
        int hi = n;
        
        while(lo<=hi){
            int len = (lo+hi)/2;
            unordered_map<long long, long long> ump;
            int i=0;
            long long cur = 0;
            int j = 0;
            for(j=0; j<len; j++){
                cur = ((cur*10 + nums[j])%mod + mod)%mod;
            }
            
            ump[cur] = 1;

            while(j<n){
                long long lv = ((binpow(10, len-1) * nums[i])%mod + mod)%mod;
                i++;
                cur =  (cur - lv + mod)%mod;
                cur = ((cur*10 + nums[j])%mod + mod)%mod;
                ump[cur]++;
                j++;
            }

            bool pos = 0;
            for(auto el: ump){
                if(el.second == 1){
                    pos = 1;
                }
            }

            if(pos){
                ans = len;
                hi = len-1;
            }else{
                lo = len+1;
            }
            
        }
        

        return ans;
    }
};