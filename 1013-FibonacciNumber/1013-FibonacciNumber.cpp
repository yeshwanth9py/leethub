// Last updated: 6/11/2026, 11:30:03 AM
class Solution {
public:
    int fib(int n) {
        if(n==1) return 1;
        if(n==0) return 0;
        int prev2 = 0;
        int prev1 = 1;
        int cur;
        for(int i=2; i<=n; i++){
            cur = prev1+prev2;
            prev2 = prev1;
            prev1 = cur;
        }
        return cur;
    }
};