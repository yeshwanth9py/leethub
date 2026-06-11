// Last updated: 6/11/2026, 11:09:27 AM
class Solution {
public:
    bool validDigit(int n, int x) {
        if(n == 0) return 0;
        string s = to_string(n);
        if(s[0]-'0' == x) return 0;
        for(int i=1; i<s.size(); i++){
            if(s[i]-'0' == x) return 1;
        }

        return 0;
    }
};