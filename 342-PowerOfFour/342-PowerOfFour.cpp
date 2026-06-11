// Last updated: 6/11/2026, 11:33:39 AM
class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<=0) return 0;
        int ind = log2(n);
        cout<<ind<<" ";
        if((1LL<<ind) == n){
            if((ind&1) == 0){
                return 1;
            }
        }
        return 0;
    }
};