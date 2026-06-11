// Last updated: 6/11/2026, 11:26:29 AM
class Solution {
public:
    const int mod = 1e9+7;
    int concatenatedBinary(int n) {
        long long numb = 0;
        for(int i=1; i<=n; i++){
            int sz = 1+log2(i);
            numb = 1LL*numb*(pow(2, sz));
            numb = numb+i;
            numb = (numb%mod + mod)%mod;
        }
        return numb;
    }
};