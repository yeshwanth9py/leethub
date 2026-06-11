// Last updated: 6/11/2026, 11:29:23 AM
class Solution {
public:
    string defangIPaddr(string address) {
        string ans = "";
        for(char ch: address){
            if(ch == '.'){
                ans += "[.]";
            }else{
                ans+=ch;
            }
        }

        return ans;
    }
};