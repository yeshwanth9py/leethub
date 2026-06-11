// Last updated: 6/11/2026, 11:13:30 AM
class Solution {
public:
    bool scoreBalance(string s) {
        int ts = 0;
        for(int i=0; i<s.length(); i++){
            ts += (s[i]-'a')+1;
        }

        int cs = 0;
        int rs = ts;
        for(int i=0; i<s.length(); i++){
            cs += (s[i]-'a')+1;
            rs -= (s[i]-'a')+1;
            if(cs == rs) return 1;
        }
        return 0;
    }
};