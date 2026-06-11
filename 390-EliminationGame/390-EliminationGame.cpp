// Last updated: 6/11/2026, 11:33:24 AM
class Solution {
public:
    int lastRemaining(int n) {
        int head = 1;
        bool ltr = 1;
        int step = 1;
        int rem = n;

        while(rem>1){
            if(ltr){
                head = head + step;
            }else{
                if(rem%2 == 0){
                    head = head;
                }else{
                    head = head+step;
                }
            }
            rem = floor(rem/2);
            step = step*2;
            ltr = !ltr;
        }

        return head;

    }
};