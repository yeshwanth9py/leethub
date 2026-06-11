// Last updated: 6/11/2026, 11:26:23 AM
class Solution {
public:
    int totalMoney(int n) {
        int all = n/7;
        int extill = n%7;
        // if(extill == 0) extill = 0;

        int ans = 0;
        for(int i=1; i<=7; i++){
            int tot = all+(extill>=i);
            int rsum = tot*((2*i) + (tot-1))/2;
            ans += rsum;
        }

        return ans;
    }
};