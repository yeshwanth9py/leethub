// Last updated: 6/11/2026, 11:20:54 AM


class Solution {
public:
    const long long mod = 1e9+7;
    int sumOfPower(vector<int>& arr) {
        long long n = arr.size();
        sort(arr.begin(), arr.end());

        long long s = 0;
        long long ans = 0;
        for(long long i=0; i<n; i++){
            long long el = arr[i];
            long long cur = ((el*el)%mod + mod)%mod;
            cur = ((cur*(s+el))%mod + mod)%mod;
            ans = ((ans+cur)%mod + mod)%mod;
            s = ((s*2 + el)%mod + mod)%mod;
        }

        return ans;

    }
};