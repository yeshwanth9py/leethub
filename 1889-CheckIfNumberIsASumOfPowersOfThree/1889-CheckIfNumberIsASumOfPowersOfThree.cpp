// Last updated: 6/11/2026, 11:26:02 AM
class Solution {
public:
    bool checkPowersOfThree(int n) {
        while(n){
            int rem = n%3;
            if(rem == 2) return false;
            n = n/3;
        }

        return 1;
    }
};