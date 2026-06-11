// Last updated: 6/11/2026, 11:38:40 AM
class Solution {
public:
    bool isPalindrome(int x) {
        long long revn = 0;
        long long on = x;
        while(x){
            long long ld = abs(x%10);
            revn = revn*10+ld;
            x = x/10;
        }

        return revn == on;
    }
};