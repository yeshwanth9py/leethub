// Last updated: 6/11/2026, 11:23:13 AM
class Solution {
public:
    int countCollisions(string s) {
        int prevr = 0;
        int prevs = 0;
        int n = s.size();
        int ans = 0;
        for(int i=0; i<n; i++){
            if(s[i] == 'R'){
                prevr++;
                prevs = 0;
            }else if(s[i] == 'L'){
                if(prevr>0){
                    ans += (prevr+1);
                    prevs = 1;
                    prevr = 0;
                }else if(prevs>0){
                    ans += 1;
                    prevs = 1;
                }else{
                    prevs = 0;
                }
            }else{
                if(prevr>0){
                    ans += prevr;
                }
                prevr = 0;
                prevs = 1;
            }

        }


        return ans;
    }
};