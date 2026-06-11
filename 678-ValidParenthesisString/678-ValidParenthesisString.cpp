// Last updated: 6/11/2026, 11:31:59 AM
class Solution {
public:
    bool checkValidString(string s) {
        int omin = 0;
        int omax = 0;
        for(int i=0; i<s.size(); i++){
            if(s[i] == '('){
                omin++;
                omax++;
            }else if(s[i] == ')'){
                omin--;
                omax--;
            }else{
                omin--;
                omax++;
            }
            if(omin<0){
                omin = 0;
            }
            if(omax<0){
                return false;
            }
        }
        if(omin==0) return true;
        return false;
    }
};