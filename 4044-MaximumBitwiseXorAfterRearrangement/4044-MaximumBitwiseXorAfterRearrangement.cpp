// Last updated: 6/11/2026, 11:13:35 AM
class Solution {
public:
    string maximumXor(string s, string t) {
        int no1 = 0;
        int no0 = 0;
        for(int i=0; i<t.size(); i++){
            if(t[i] == '0'){
                no0++;
            }else{
                no1++;
            }
        }

        string ans = "";
        for(int i=0; i<s.size(); i++){
            if(s[i] == '0'){
                if(no1>0){
                    ans.push_back('1');
                    no1--;
                }else{
                    ans.push_back('0');
                    no0--;
                }
            }else{
                if(no0>0){
                    ans.push_back('1');
                    no0--;
                }else{
                    ans.push_back('0');
                    no1--;
                }
            }
        }
        return ans;
    }
};