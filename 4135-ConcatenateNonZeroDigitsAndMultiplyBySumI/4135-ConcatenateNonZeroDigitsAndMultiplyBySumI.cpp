// Last updated: 6/11/2026, 11:12:11 AM
class Solution {
public:
    long long sumAndMultiply(int n) {
        int s = 0;
        if(n == 0) return 0;
        string me = "";
        string g = to_string(n);
        for(char ch: g){
            if(ch != '0'){
                me.push_back(ch);
                s += ch-'0';
            }
        }

        long long nnum = stoll(me);
        nnum = nnum*s;

        return nnum;
        
        
    }
};