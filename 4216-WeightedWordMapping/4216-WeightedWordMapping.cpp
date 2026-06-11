// Last updated: 6/11/2026, 11:10:30 AM
class Solution {
public:
    string mapWordWeights(vector<string>& w, vector<int>& wts) {
        string ans = "";
        unordered_map<int, char> ump;
        int sc = 0;
        for(char ch='z'; ch>='a'; ch--){
            ump[sc] = ch;
            sc++;
        }
        
        for(int i=0; i<w.size(); i++){
            int sc = 0;
            for(char ch: w[i]){
                sc += wts[ch-'a'];
            }
            sc %= 26;
            char ch = ump[sc];
            ans.push_back(ch);
        }
        return ans;
    }
};