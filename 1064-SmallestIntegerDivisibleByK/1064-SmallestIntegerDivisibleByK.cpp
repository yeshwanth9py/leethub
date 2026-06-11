// Last updated: 6/11/2026, 11:29:42 AM
class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if(k == 1) return 1;
        
        int rem = 1;
        int x = 1;

        for(int i=0; i<k; i++){
            rem = ((x*10)%k + rem)%k;
            x = (x*10)%k;
            if(rem == 0 || rem == k) return (i+2);
        }

        return -1;
    }
};