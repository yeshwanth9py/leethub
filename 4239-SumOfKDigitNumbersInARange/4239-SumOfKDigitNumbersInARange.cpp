// Last updated: 6/11/2026, 11:10:15 AM

#define ll long long
const ll mod = 1e9+7;

class Solution {
public:
    ll binpow(ll x, ll n, ll mod){
        if(n == 0) return 1;
        if(n == 1) return x;
        ll ans = binpow(x, n/2, mod);
        ans = ((ans*ans)%mod + mod)%mod;
        if(n&1){
            ans = ((ans*x)%mod + mod)%mod;
        }
        
        return ans;
    }

    ll gsum(ll l, ll r){
        ll s2 = (r*(r+1))/2;
        int s1 = 0;
        if(l-1>=0){
            s1 = ((l-1)*l)/2;
        }
        return s2-s1;
    }

    ll sumofgp(ll k){
        ll num = (binpow(10, k, mod)-1+mod)%mod;
        ll den = 9;
        return ((num*binpow(den, mod-2, mod))%mod + mod)%mod;
    }
    
    int sumOfNumbers(int l, int r, int k) {
        ll pos = (r-l+1);
        ll ex = binpow(pos, k-1, mod);
        //ll ex = pos^(k-1)
        //10^(k-1)*(sum(l..r))*(ex) + ....ktimes
        ll gs = gsum(l, r);
        ll ans = ((gs*ex)%mod + mod)%mod;
        ll combi = sumofgp(k);
        ans = ((ans*combi)%mod + mod)%mod;

        return ans;
    }
};