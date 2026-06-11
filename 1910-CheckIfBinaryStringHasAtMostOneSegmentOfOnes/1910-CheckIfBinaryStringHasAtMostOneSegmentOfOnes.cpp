// Last updated: 6/11/2026, 11:25:56 AM
class Solution {
public:
    bool checkOnesSegment(string s) {
        int i=0;
        int cnt = 0;
        while(i<s.size()){
            if(s[i] == '1'){
                cnt++;
            }else{
                break;
            }
            i++;
        }

        while(i<s.size()){
            if(s[i] == '1') return 0;
            i++;
        }

        return 1;
    }
};