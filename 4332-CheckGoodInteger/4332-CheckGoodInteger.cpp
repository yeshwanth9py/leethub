// Last updated: 6/14/2026, 7:26:52 PM
class Solution {
public:
    bool checkGoodInteger(int n) {
        int ds = 0;
        int ss = 0;
        while(n>0){
            int ld = n%10;
            ds += ld;
            ss += (ld*ld);
            n = n/10;
        }
        return (ss-ds)>=50;
    }
};