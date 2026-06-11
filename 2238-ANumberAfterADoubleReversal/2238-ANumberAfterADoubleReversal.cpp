// Last updated: 6/11/2026, 11:23:51 AM
class Solution {
public:
    bool isSameAfterReversals(int num) {
        int dupnum = num;
        int revnum = 0;
        
        while(num>0){
            int ld = num%10;
            revnum = revnum*10 + ld;
            num = num/10;
        }
        
        num = revnum;
        int newnum = 0;
        while(num>0){
            int ld = num%10;
            newnum = newnum*10 + ld;
            num = num/10;
        }

        return newnum == dupnum;
        

    }
};