// Last updated: 6/11/2026, 11:25:55 AM
class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1.size()!=s2.size()) return false;
        char ch1 = '-';
        char ch2 = '-';
        int flag = 1;
        for(int i=0; i<s1.size(); i++){
            if(s1[i]!=s2[i]){
                if(!flag) return false;
                else if(ch1 == '-'){
                    ch1 = s1[i];
                    ch2 = s2[i];
                    flag = 2;
                }else if(ch2 == s1[i] && ch1==s2[i]){
                    flag = 0;
                }else{
                    return false;
                }
            }
        }
        cout<<flag<<" ";
        if(flag == 2){
            return false;
        }
        return true;
    }
};