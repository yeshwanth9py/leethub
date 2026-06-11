// Last updated: 6/11/2026, 11:25:11 AM
class Solution {
public:
    int mod = 1e9+7;
    long long binpow(long long a, long long b){
        if(b == 0){
            return 1;
        }
        a %= mod;
        if(b == 1){
            return a;
        }
        if(b%2 == 1){
            return (1LL*a%mod*binpow(a, b-1)%mod)%mod;
        }else{
            long long ans = binpow(a, b/2)%mod;
            return (ans%mod*ans%mod)%mod;
        }
        
    }
    int countGoodNumbers(long long n) {
        if(n%2==1){
            int ans = (binpow(5, (n+1)/2)%mod*binpow(4, n/2)%mod)%mod;
            return ans;
        }else{
            int ans = (binpow(5, n/2)%mod*binpow(4, n/2)%mod)%mod;
            return ans;
        }
    }
};