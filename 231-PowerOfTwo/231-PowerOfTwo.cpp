// Last updated: 6/11/2026, 11:34:28 AM
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0) return 0;
         return ((n&(n-1)) == 0);
    }
};