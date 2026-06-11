// Last updated: 6/11/2026, 11:16:39 AM
class Solution {
public:
    const long long mod = 1e9+7;
    long long fact[101000];
    long long invfact[101000];

    long long binpow(long long x, long long n){
        x = x%mod;
        if(n == 0) return 1;
        long long ans = binpow(x, n/2);
        ans = ((1LL*ans*ans)%mod + mod)%mod;
        if(n&1){
            ans = ((1LL*ans*x)%mod + mod)%mod;
        }

        return ans;
    }

    void pre(){
        fact[0] = fact[1] = 1;
        for(long long i=2; i<101000; i++){
            fact[i] = ((1LL*i*(fact[i-1]))%mod + mod)%mod;
        }
        invfact[101000-1] = binpow(fact[101000-1], mod-2);
        for(long long i=101000-2; i>=0; i--){
            invfact[i] = ((1LL*invfact[i+1] * (i+1))%mod + mod)%mod;
        }
    }

    long long ncr(long long n, long long r){
        long long num = (((1LL*fact[n] * invfact[n-r])%mod)*(1LL*invfact[r])%mod + mod)%mod;
        return num;
    }
    int minMaxSums(vector<int>& nums, int k) {
        long long n = nums.size();
        pre();

        vector<long long> all;
        for(long long el: nums) all.push_back(el);
        
        sort(all.begin(), all.end());

        long long ans = 0;
        for(long long i=0; i<n; i++){
            long long sm = i;
            long long cur = 0;
            for(long long j=0; j<=min(1LL*k-1, sm); j++){
                cur += 1LL*ncr(sm, j)*all[i];
                cur = (cur%mod + mod)%mod;
            }

            long long big = n-i-1;
            for(long long j=0; j<=min(1LL*k-1, big); j++){
                cur += 1LL*ncr(big, j)*all[i];
                cur = (cur%mod + mod)%mod;
            }

            ans += cur;
            ans = (ans%mod + mod)%mod;
        }

        return ans;

    }
};


