// Last updated: 6/11/2026, 11:21:51 AM
class Solution {
public:
    int bestClosingTime(string s) {
        int y = 0;
        for(int i=0; i<s.size(); i++){
            if(s[i] == 'Y'){
                y++;
            }
        }

        int minp = y;
        int ans = 0;
        int curp = 0;
        for(int i=0; i<s.size(); i++){
            if(s[i] == 'Y'){
                y--;
            }else{
                curp++;
            }

            if(curp+y<minp){
                minp = curp+y;
                ans = i+1;
            }
        }

        return ans;
    }
};