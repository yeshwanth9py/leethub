// Last updated: 6/11/2026, 11:30:41 AM
class Solution {
public:
    int binaryGap(int n) {
        int sz = log2(n);
        int lp = -1;
        int ans = 0;
        for(int i=sz; i>=0; i--){
            if((n&(1LL<<i)) != 0){
                if(lp != -1){
                    ans = max(ans, lp-i);
                }
                lp = i;
            }
        }
        return ans;
    }
};