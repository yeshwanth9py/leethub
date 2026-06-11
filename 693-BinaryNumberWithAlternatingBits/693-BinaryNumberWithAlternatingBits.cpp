// Last updated: 6/11/2026, 11:31:54 AM
class Solution {
public:
    bool hasAlternatingBits(int n) {
        int sz = log2(n);
        
        int r = 1;
        for(int i=sz; i>=0; i--){
            cout<<i<<" ";
            if((n&(1LL<<i)) && r==1 || (r == 0 && (n&(1LL<<i)) == 0)){
                r = !r;
            }else{
                cout<<i<<" ";
                return 0;
            }
        }

        return 1;
    }
};