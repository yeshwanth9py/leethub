// Last updated: 6/11/2026, 11:30:33 AM
class Solution {
public:
    long long mod = 1e9+7;
    long long gcd(int a, int b){
        if(a==0 || b==0){
            return a+b;
        }
        return gcd(b, a%b);
    }

    long long lcm(long long a, long long b){
        return (a*b)/(gcd(a, b));
    }

    bool check(long long md, long long a, long long b, long long n){
        long long noa = md/a;
        long long nob = md/b;
        long long noab = md/lcm(a, b);
        return noa+nob-noab>=n;
    }

    int nthMagicalNumber(int n, int a, int b) {
        long long lo = min(a, b);
        long long hi = 1LL*n*max(a, b);
        long long ans = -1;
        while(lo<=hi){
            long long mid = (lo+hi)/2;
            if(check(mid, a, b, n)){
                ans = mid;
                hi = mid-1;
            }else{
                lo = mid+1;
            }
        }
        return ans%mod;
    }
};