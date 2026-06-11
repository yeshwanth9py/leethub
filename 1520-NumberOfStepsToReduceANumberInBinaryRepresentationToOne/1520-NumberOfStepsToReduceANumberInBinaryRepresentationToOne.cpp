// Last updated: 6/11/2026, 11:27:40 AM
class Solution {
public:
    int numSteps(string s) {
        int car = 0;
        int op = 0;
        for(int i=s.size()-1; i>=1; i--){
            int v = car + (s[i]-'0');
            if(v == 2){
                op++;
                car = 1;
            }else if(v == 1){
                op += 2;
                car = 1;
            }else{
                op++;
            }
        }
        int v = car + (s[0]-'0');
        if(v == 2) op++;
        return op;
    }
};