// Last updated: 6/11/2026, 11:18:29 AM
class Solution {
public:
    int numberOfSpecialChars(string w) {
        vector<int> small(26, -1), big(26, -1);

        for(int i=0; i<w.size(); i++){
            char ch = w[i];
            if(ch>='a' && ch<='z'){
                small[ch-'a'] = i;
            }else{
                if(big[ch-'A'] == -1){
                    big[ch-'A'] = i;
                }
            }
        }

        int tot = 0;
        for(int i=0; i<26; i++){
            if(big[i] == -1 || small[i] == -1) continue;
            if(big[i]>small[i]){
                tot++;
                // cout<<i<<" ";
            }
        }

        return tot;

    }
};