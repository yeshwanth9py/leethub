// Last updated: 6/11/2026, 11:08:58 AM
class Solution {
public:
    int sumOfGoodIntegers(int n, int k) {
        int ans = 0;
        for(int x=1; x<=n+k; x++){
            if(abs(n-x)<=k && (n&x) == 0){
                ans += x;
            }
        }

        return ans;
    }
};