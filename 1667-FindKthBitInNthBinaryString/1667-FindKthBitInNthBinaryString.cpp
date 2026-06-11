// Last updated: 6/11/2026, 11:27:00 AM
class Solution {
public:
    char findKthBit(int n, int k) {
        if(n == 1){
            return '0';
        }

        int inv = 0;
        int len = (1LL<<n)-1;
        while(1){
            if(len == 1){
                if(inv%2 == 0) return '0';
                return '1';
            }
            int mid = (len/2)+1;
            if(k == mid){
                if(inv%2 == 0) return '1';
                return '0';
            }
            if(k<mid){
                len = len/2;
            }else{
                inv++;
                k = len-k+1;
                len = len/2;
            }
        }

        
    }
};



