// Last updated: 6/11/2026, 11:29:46 AM
class Solution {
public:
    int bitwiseComplement(int n) {
        if(n == 0) return 1;
        int sz = 1+log2(n);
        int mask = (1LL<<(sz))-1;
        // cout<<bitset<10> (mask)<<endl;
        return (mask^n);
    }
};