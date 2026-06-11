// Last updated: 6/11/2026, 11:18:08 AM
class Solution {
public:
    bool doesAliceWin(string s) {
        int cnt = 0;
        for(int i=0; i<s.length(); i++){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'o' || s[i] == 'u' || s[i] == 'i'){
                cnt++;
            }
        }

        if((cnt%2) == 1){
            return 1;
        }
        if(cnt == 0){
            return 0;
        }

        return 1;



    }
};