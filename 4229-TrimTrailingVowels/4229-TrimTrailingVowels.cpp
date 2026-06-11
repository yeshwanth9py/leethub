// Last updated: 6/11/2026, 11:10:19 AM
class Solution {
public:
    string trimTrailingVowels(string s) {
        int i=s.size()-1;
        while(i>=0){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
                i--;
            }else{
                break;
            }
        }

        s = s.substr(0, i+1);

        return s;
    }
};