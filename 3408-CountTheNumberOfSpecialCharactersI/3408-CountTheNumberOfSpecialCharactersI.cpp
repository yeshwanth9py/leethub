// Last updated: 6/11/2026, 11:18:24 AM
class Solution {
public:
    int numberOfSpecialChars(string s) {
        vector<int> cap(26, 0);
        vector<int> sml(26, 0);

        vector<int> ans(26, 0);

        int sp = 0;
        for(char ch: s){
            if(ch>='a' && ch<='z'){
               int ind = ch-'a';
               if(cap[ind] == 1) ans[ind] = 1;
               sml[ind] = 1;
            }else{
                int ind = ch - 'A';
                if(sml[ind] == 1) ans[ind] = 1;
                cap[ind] = 1;
            }
        }

        return (accumulate(ans.begin(), ans.end(), 0));
    }
};