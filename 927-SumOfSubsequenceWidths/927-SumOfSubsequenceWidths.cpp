// Last updated: 6/11/2026, 11:30:28 AM
class Solution {
public:
    const long long mod = 1e9+7;
    long long binpow(long long x, long long n){
        if(n == 0) return 1;
        long long ans = binpow(x, n/2);
        ans = ((ans*ans)%mod + mod)%mod;
        if(n&1){
            ans = ((ans*x)%mod + mod)%mod;
        }

        return ans;
    }

    int sumSubseqWidths(vector<int>& arr) {
        long long n = arr.size();
        sort(arr.begin(), arr.end());
        long long ans = 0;

        for(long long i=0; i<n; i++){
            long long nos = i;
            long long nob = n-i-1;
            ans += (((binpow(2, nos)-1)*arr[i])%mod + mod)%mod;
            ans = (ans%mod + mod)%mod;
            ans -= (((binpow(2, nob)-1)*arr[i])%mod + mod)%mod;
            ans = (ans+mod)%mod;
        }

        return ans;
    }
};

