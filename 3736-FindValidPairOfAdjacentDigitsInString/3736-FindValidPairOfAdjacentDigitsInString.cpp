// Last updated: 6/11/2026, 11:16:32 AM
class Solution {
public:
    string findValidPair(string s) {
        unordered_map<char, int> ump;
        for(int i=0; i<s.size(); i++){
            ump[s[i]]++;
        }
        for(int i=0; i<s.size()-1; i++){
            if(s[i]!=s[i+1] && (ump[s[i]] == s[i]-'0') && (ump[s[i+1]] == s[i+1]-'0')){
                // cout<<s[i]<<s[i+1]<<endl;
                string ans = to_string(s[i]-'0')+to_string(s[i+1]-'0');
                return ans;
            }
        }
        return "";
    }
};