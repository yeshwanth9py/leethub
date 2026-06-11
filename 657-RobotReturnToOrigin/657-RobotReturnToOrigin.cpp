// Last updated: 6/11/2026, 11:32:06 AM
class Solution {
public:
    bool judgeCircle(string m) {
        int cur = 0;
        for(char ch: m){
            if(ch == 'L'){
                cur -= 1;
            }else if(ch == 'R'){
                cur += 1;
            }
        }

        if(cur!=0) return 0;

        for(char ch: m){
            if(ch == 'U'){
                cur += 1;
            }else if(ch == 'D'){
                cur -= 1;
            }
        }
        return cur == 0;
    }
};