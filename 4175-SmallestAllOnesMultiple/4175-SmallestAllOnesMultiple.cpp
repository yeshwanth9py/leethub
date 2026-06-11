// Last updated: 6/11/2026, 11:11:08 AM
class Solution {
public:
    long long binpow(long long x, long long n){
        if(n == 0) return 1;
        long long ans = binpow(x, n/2);
        ans = ans*ans;
        if(n&1){
            ans = 1LL*ans*x;
        }
        return ans;
    }
    int minAllOneMultiple(int k) {
        if(k == 1) return 1;

        long long cur = 1;
        long long po = 1;
        for(long long m=1; m<=k; m++){
            po = (po*10)%k;
            cur = (cur + po)%k;
            if(cur == 0) return m+1;
        }
        

        return -1;
    }
};