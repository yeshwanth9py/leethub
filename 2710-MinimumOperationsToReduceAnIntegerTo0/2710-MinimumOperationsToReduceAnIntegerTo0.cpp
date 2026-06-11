// Last updated: 6/11/2026, 11:21:09 AM
class Solution {
public:
    int minOperations(int n) {
        int op = 0;
        int prev = 0;
        int run = 0;
        
        for(int i=0; i<31; i++){
            if((n&(1LL<<i))){
                prev = 1;
                run++;
            }else{
                if(prev==1){
                    if(run>1){
                        op += 2;
                        prev=0;
                        if((n&(1LL<<(i+1)))){
                            op -= 1;
                            prev = 1;
                            run = 1;
                        }
                    }else{
                        op++;
                        run = 0;
                        prev = 0;
                    }
                }else{
                    prev = 0;
                    run = 0;
                }
            }
        }

        return op;


    }
};