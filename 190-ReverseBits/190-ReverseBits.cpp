// Last updated: 6/11/2026, 11:35:17 AM
class Solution {
public:
    int reverseBits(int n) {
        int tot = 31;
        int ans = 0;
        for(int i=0; i<31; i++){
            if((n&(1LL<<i))){
                ans |= (1LL<<(tot-i));
            }
        }
        return ans;
    }
};