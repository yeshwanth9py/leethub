// Last updated: 6/11/2026, 11:11:15 AM
class Solution {
public:
    long long lastInteger(long long n) {
        if(n == 1) return 1;
        long long f = 1;
        long long l = n;
        long long step = 2;
        long long cur = f;
        long long rem = n;

        long long ty = 0;
        while(rem!=1){
            if(ty == 0){
                rem = rem/2 + rem%2;
                long long x = (l-f)/step;
                long long nl = f+(x*step);
                if(nl>l){
                    nl = nl-step;
                }
                l = nl;
                ty = !ty;
                step = step*2;
            }else{
                rem = rem/2 + rem%2;
                long long x = (l-f)/step;
                long long nf = l-(x*step);
                if(nf<f){
                    nf += step;
                }
                f = nf;
                ty = !ty;
                step = step*2;
            }
        }

        if(ty == 0){
            return f;
        }else{
            return l;
        }
        
    }
};