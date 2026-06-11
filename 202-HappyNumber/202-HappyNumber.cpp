// Last updated: 6/11/2026, 11:35:03 AM
class Solution {
public:
    int sqsum(int num){
        int tsum = 0;
        while(num){
            int ld = num%10;
            tsum += ld*ld;
            num = num/10;
        }
        return tsum;
    }
    bool isHappy(int n) {
        int slow = n;
        int fast = n;
        do {
            slow = sqsum(slow);
            fast = sqsum(sqsum(fast));
        }while(slow != fast);

        if(slow == 1){
            return true;
        }
        return false;
    }
};