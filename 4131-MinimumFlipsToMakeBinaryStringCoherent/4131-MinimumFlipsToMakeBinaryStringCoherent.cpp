// Last updated: 6/11/2026, 11:12:15 AM
class Solution {
public:
    int minFlips(string s) {
        if(s.size()<=2) return 0;
        int c1 = 0;

        int n1 = 0;
        int n0 = 0;

        for(int i=0; i<s.size(); i++){
            if(s[i] == '1'){
                n1++;
            }else{
                n0++;
            }
        }

        c1 = n0;

        //case 2
        c1 = min(c1, n1);


        //case 3
        if(n1>0) c1 = min(c1, n1-1);

        //case 4
        int ex = n1 - (s[0] == '1') - (s[s.size()-1] == '1');
        int cur = ex + ((s[0] != '1')) + (s[s.size()-1] != '1');
        c1 = min(c1, cur);

        return c1;
    }
};