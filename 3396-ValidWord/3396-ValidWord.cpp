// Last updated: 6/11/2026, 11:18:32 AM
class Solution {
public:
    bool isValid(string word) {
        if(word.size()<3) return 0;
        bool isvow = 0;
        bool iscon = 0;
        unordered_map<char, bool> ump = {{'a', 1}, {'e', 1}, {'i', 1}, {'o', 1}, {'u', 1}};
        for(char ch: word){
            if(!isalnum(ch)) return 0;
            ch = tolower(ch);
            if(ch>='0' && ch<='9') continue;
            if(ump.find(ch)!=ump.end()){
                isvow = 1;
            }else{
                iscon = 1;
            }
        }  

        return (isvow && iscon);  

    }
};