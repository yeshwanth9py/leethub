// Last updated: 6/11/2026, 11:37:44 AM
class Solution {
public:
    double myPow(double x, long long n) {
        if(n<0){
            return 1.0/myPow(x, abs(n));
        }
        if(n == 0) return 1;
        if(x == 1) return x;
        double ans = myPow(x, n/2);
        ans = ans*ans;
        if(n%2 == 1){
            ans = ans*x;
        }
        return ans;
    }
};