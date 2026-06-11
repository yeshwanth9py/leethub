// Last updated: 6/11/2026, 11:20:25 AM
class Solution {
public:
    int furthestDistanceFromOrigin(string s) {
        int r = 0;
        int a = 0;
        for(char ch: s){
            if(ch == 'R'){
                r++;
            }else if(ch == 'L'){
                r--;
            }else{
                a++;
            }
        }

        if(r>0){
            return r+a;
        }else{
            return abs(r-a);
        }

    }
};