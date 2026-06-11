// Last updated: 6/11/2026, 11:11:04 AM
class Solution {
public:
    int vowelConsonantScore(string s) {
        unordered_map<char, int> ump = {{'a', 1}, {'e', 1}, {'i', 1}, {'o', 1}, {'u', 1}};
        int v = 0;
        int c = 0;
        for(char ch: s){
            if(ump[ch]>0){
                v++;
            }else if(ch>='a' && ch<='z'){
                c++;
            }
        }
        if(c>0){
            int ans = v/c;
            return ans;
        }
        return 0;
    }
};