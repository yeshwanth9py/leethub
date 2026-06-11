// Last updated: 6/11/2026, 11:10:47 AM
class Solution {
public:
    int countMonobit(int n) {
        if(n == 0) return 1;
        int sz = log2(n)+1;
        // cout<<bitset<6>((1LL<<(sz))-1)<<" ";
        if(n == ((1LL<<(sz)) -1)) return sz+1;
        return sz;
    }
};