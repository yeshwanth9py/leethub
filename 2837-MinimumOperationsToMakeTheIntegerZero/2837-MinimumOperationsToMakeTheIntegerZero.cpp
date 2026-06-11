// Last updated: 6/11/2026, 11:20:47 AM
class Solution {
public:
    int makeTheIntegerZero(long long num1, long long num2) {
        for(int i=0; i<60; i++){
            long long val = num1 - i*num2;
            if(val<0) continue;
            long long minopr = __builtin_popcountll(val);
            long long maxopr = val;
            if(i<=maxopr && i>=minopr){
                return i;
            }
        }
        return -1;
    }
};