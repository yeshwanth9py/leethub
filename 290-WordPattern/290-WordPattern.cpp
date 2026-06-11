// Last updated: 6/11/2026, 11:34:05 AM
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> ump;
        vector<string> ls;
        string temp = "";
        for(int i=0; i<s.size(); i++){
            if(s[i] == ' '){
                ls.push_back(temp);
                temp = "";
            }else{
                temp += s[i];
            }
        }
        if(temp!=""){
            ls.push_back(temp);
            temp = "";
        }

        if(pattern.size()!=ls.size()){
            return false;
        }

        for(int i=0; i<pattern.size(); i++){
            char ch = pattern[i];
            if(ump.find(ch)==ump.end()){
                ump[ch] = ls[i];
            }else{
                if(ump[ch]!=ls[i]){
                    return false;
                }
            }
        }

        unordered_map<string, char> ump2;
        for(int i=0; i<pattern.size(); i++){
            string ch = ls[i];
            if(ump2.find(ch)==ump2.end()){
                ump2[ch] = pattern[i];
            }else{
                if(ump2[ch]!=pattern[i]){
                    return false;
                }
            }
        }
        
        return true;
    }
};