// Last updated: 6/11/2026, 11:32:32 AM
class Solution {
public:
    string reverseWords(string s) {
        istringstream stream(s);
        string word;

        vector<string> words;

        while(stream>>word){
            words.push_back(word);
        }
        string ans = "";

        for(string word: words){
            reverse(word.begin(), word.end());
            if(ans == ""){
                ans += word;
            }else{
                ans += " "+word;
            }
        }

        return ans;
    }
};