// Last updated: 6/11/2026, 11:22:02 AM
class Solution {
public:
    vector<string> twoEditWords(vector<string>& q, vector<string>& d) {
        unordered_map<string, int> ump;
        for(string s: d){
            for(int i=0; i<s.size(); i++){
                string temp = s;
                for(int j=0; j<26; j++){
                    temp[i] = char(j+'a');
                    ump[temp] = 1;
                }
            }
        }

        vector<string> ans;
        for(string s: q){
            bool pres = 0;
            for(int i=0; i<s.size(); i++){
                string temp = s;
                for(int j=0; j<26; j++){
                    temp[i] = char(j+'a');
                    if(ump[temp] == 1){
                        pres = 1;
                        break;
                    }
                }
            }
            if(pres){
                ans.push_back(s);
            }
        }

        return ans;
    }
};
