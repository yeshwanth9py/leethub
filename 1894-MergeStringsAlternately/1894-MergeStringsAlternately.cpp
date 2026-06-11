// Last updated: 6/11/2026, 11:25:59 AM
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int l = 0;
        int r = 0;
        string ans="";
        while(l<word1.size() && r<word2.size()){
            ans += word1[l];
            ans += word2[r];
            l++;
            r++;
        }
        if(l<word1.size()){
            ans+=word1.substr(l, word1.size()-l);
        }

        if(r<word2.size()){
            ans+=word2.substr(r, word2.size()-r);
        }

        return ans;
    }


};