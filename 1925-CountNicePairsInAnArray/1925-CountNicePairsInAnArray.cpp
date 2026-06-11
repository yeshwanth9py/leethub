// Last updated: 6/11/2026, 11:25:48 AM
class Solution {
public:
    const long long mod = 1e9+7;
    long long findrev(long long num){
        long long rev = 0;
        while(num){
            long long ld = num%10;
            rev = rev*10 + ld;
            num = num/10;
        }
        return rev;
    }


    int countNicePairs(vector<int>& nums) {
        long long n = nums.size();
        unordered_map<long long, long long> ump;
        long long ans = 0;
        for(long long i=0; i<n; i++){
            int v = (nums[i] - findrev(nums[i])+mod)%mod;
            ans += ump[v];
            ans = (ans%mod+mod)%mod;
            ump[v]++;
        }

        return ans;
    }
};