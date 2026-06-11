// Last updated: 6/11/2026, 11:10:43 AM
class Solution {
public:
    string reverseByType(string s) {
        vector<char> let;
        vector<char> spl;
        for(char ch: s){
            if(ch>='a' && ch<='z'){
                let.push_back(ch);
            }else{
                spl.push_back(ch);
            }
            
        }

        reverse(let.begin(), let.end());
        reverse(spl.begin(), spl.end());
        int i1 = 0;
        int i2 = 0;
        string ans = "";
        for(int i=0; i<s.size(); i++){
            if(s[i]>='a' && s[i]<='z'){
                ans.push_back(let[i1]);
                i1++;
            }else{
                ans.push_back(spl[i2]);
                i2++;
            }
        }

        return ans;

        
    }
};