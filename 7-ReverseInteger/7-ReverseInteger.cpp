// Last updated: 6/11/2026, 11:38:43 AM
class Solution {
public:
    int reverse(int x) {
        long long newn = 0;
        while(x){
            long long ld = x%10;
            newn = newn*10+ld;
            if(newn>=pow(2, 31) || newn<=-pow(2, 31)){
                return 0;
            }
            x = x/10;
        }

        return newn;
    }
};