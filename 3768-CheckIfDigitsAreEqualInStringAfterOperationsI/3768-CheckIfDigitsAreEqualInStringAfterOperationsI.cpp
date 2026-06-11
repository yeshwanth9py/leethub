// Last updated: 6/11/2026, 11:16:08 AM
class Solution {
public:
    bool hasSameDigits(string s) {
        
        int iter = 0;
        while(s.size()>2){
            // iter++;
            // if(iter>=100) return 0;
            string t = "";
            for(int i=0; i<s.length()-1; i++){
                int cur = ((s[i]-'0') + (s[i+1]-'0'))%10;
                t.append(to_string(cur));
            }
            s = t;
            // cout<<s<<" ";
        }
        return s[0] == s[1];
    
    }
};