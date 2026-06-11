// Last updated: 6/11/2026, 11:35:34 AM
class Solution {
public:
    string reverseWords(string s) {
        vector<string> v;
        string temp = "";

        bool flag = false;
        for(int i=0; i<s.size(); i++){
            if(s[i] != ' '){
                temp += s[i];
            }else{
                if(temp=="") continue;
                v.push_back(temp);
                temp = "";
            }
        }

        v.push_back(temp);

        reverse(v.begin(), v.end());

        string op = "";

        for(string s: v){
            if(op!=""){
                op += " "+s;
            }else{
                op = s;
            }
        }

        return op;
    }
};