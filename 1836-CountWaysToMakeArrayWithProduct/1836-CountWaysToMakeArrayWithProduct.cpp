// Last updated: 6/11/2026, 11:26:14 AM
class Solution {
public:
    const long long mod = 1e9+7;
    vector<long long> spf;
    static const long long maxs = 1e5;
    long long fact[maxs];
    long long ifact[maxs];

    long long binpow(long long x, long long n, long long mod){
        if(n == 0) return 1;
        if(n == 1) return x;
        long long ans = binpow(x, n/2, mod);
        ans = (ans*ans)%mod;
        if(n&1){
            ans = (ans*x)%mod;
        }

        return ans;
    }

    void pre(){
        spf.resize(maxs, 1);
        for(long long i=1; i<maxs; i++){
            spf[i] = i;
        }

        for(long long i=2; i<maxs; i++){
            if(spf[i] == i){
                for(long long j=i*i; j<maxs; j=j+i){
                    if(spf[j] == j){
                        spf[j] = i;
                    }
                }
            }
        }

        fact[0] = fact[1] = 1;
        for(long long i=2; i<maxs; i++){
            fact[i] = (fact[i-1]*i)%mod;
            fact[i] = (fact[i]+mod)%mod;
        }

        ifact[maxs-1] = binpow(fact[maxs-1], mod-2, mod)%mod;
        // ifact[maxs-1] = (ifact[maxs-1]+mod)%mod;

        for(long long i=maxs-2; i>=0; i--){
            ifact[i] = (ifact[i+1] * (i+1))%mod;
            ifact[i] = (ifact[i]+mod)%mod;
        }
    }

    long long ncr(long long n, long long r){
        if(r == 0) return 1;
        if(n == r) return 1;
        // if(n>r) return 0;

        long long ans = (((fact[n] * ifact[n-r])%mod+mod) * ifact[r])%mod;
        ans = (ans + mod)%mod;
        return ans;
    }

    vector<int> waysToFillArray(vector<vector<int>>& queries) {
        pre();
        // cout<<ifact[1]<<endl;
        vector<int> myans;
        for(auto q: queries){
            long long n = q[0];
            long long k = q[1];

            long long el = k;
            unordered_map<int, int> ump;
            long long sump = 0;
            long long asans = 1;

            while(el>1){
                long long p = spf[el];
                long long cnt = 0;
                while(el%p == 0){
                    cnt++;
                    el = el/p;
                }
                asans = (asans * ncr(cnt+n-1, n-1))%mod;
                asans = (asans+mod)%mod;
            }
            myans.push_back(asans);
        }

        return myans;
    }
};