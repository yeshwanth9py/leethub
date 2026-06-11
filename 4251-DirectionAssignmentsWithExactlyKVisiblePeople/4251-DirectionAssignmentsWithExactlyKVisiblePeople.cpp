// Last updated: 6/11/2026, 11:10:05 AM
class Solution {
public:
    const long long mod = 1e9+7;
    long long fact[100100];
    void pre(){
        fact[0] = fact[1] = 1;
        for(long long i=2; i<100100; i++){
            fact[i] = ((fact[i-1]*(i))%mod+mod)%mod;
        }
    }

    long long binpow(long long x, long long n){
        if(n == 0) return 1;
        long long ans = binpow(x, n/2);
        ans = ((ans*ans)%mod + mod)%mod;
        if(n&1){
            ans = ((ans*x)%mod + mod)%mod;
        }
        return ans;
    }
    
    long long ncr(long long n, long long r){
        if(n<r) return 0;
        if(n == r) return 1;
        long long num = fact[n];
        // cout<<n<<" "<<r<<endl;
        long long den = ((fact[n-r]*fact[r])%mod + mod)%mod;
        den = binpow(den, mod-2);
        num = ((num*den)%mod + mod)%mod;
        return num;
    }
    
    int countVisiblePeople(int n, int pos, int k) {
        pre();
        long long al = pos;
        long long ans = 0;
        for(long long l=0; l<=al; l++){
            long long r = k-l;
            long long ar = n-pos-1;
            if(r>ar || r<0) continue;
            ans += (ncr(al, l)*ncr(ar, r))%mod;
            ans = (ans%mod + mod)%mod;
        }

        return ((2*ans)%mod + mod)%mod;
    }
};