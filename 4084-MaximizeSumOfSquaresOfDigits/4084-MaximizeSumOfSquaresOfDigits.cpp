// Last updated: 6/11/2026, 11:12:57 AM
class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string s = "";
        int rems = sum;
        for(int i=0; i<num; i++){
            if(rems>=9){
                s.push_back('9');
                rems -= 9;
            }else{
                if(rems>0){
                    s += '0'+rems;
                    rems = 0;
                }else{
                    s.push_back('0');
                }
            }
        }

        if(rems>0) return "";

        return s;
    }
};