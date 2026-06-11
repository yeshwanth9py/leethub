// Last updated: 6/11/2026, 11:31:07 AM
class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.size();
        while(n--){
            if(s == goal){
                return true;
            }
            s = s.substr(1, s.size()-1) + s[0];
        }

        return false;
    }
};