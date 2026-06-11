// Last updated: 6/11/2026, 11:19:31 AM
class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> ans;

        
        for(int w=0; w<words.size(); w++){
            string word = words[w];
            for(int i=0; i<word.size(); i++){
                char ch = word[i];
                if(ch == x){
                    ans.push_back(w);
                    break;
                }
            }
        }

        return ans;
    }
};