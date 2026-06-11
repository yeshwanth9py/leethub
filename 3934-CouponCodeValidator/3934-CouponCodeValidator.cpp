// Last updated: 6/11/2026, 11:14:40 AM
class Solution {
public:
    bool isvalid(string el){
        if(el == "") return 0;
        for(char ch: el){
            if(ch>='a' && ch<='z' || ch>='A' && ch<='Z') continue;
            if(ch-'0' >= 0 && ch-'0'<=9) continue;
            if(ch == '_') continue;
            return 0;
        }
        return 1;
    }
    vector<string> validateCoupons(vector<string>& code, vector<string>& bus, vector<bool>& isActive) {
        vector<string> ans;
        unordered_map<string, vector<string>> ump;
        for(int i=0; i<code.size(); i++){
            if(isActive[i] == 0) continue;
            if(!isvalid(code[i])) continue;
            ump[bus[i]].push_back(code[i]);
        }

        vector<string> ineed = {"electronics", "grocery", "pharmacy", "restaurant"};

        for(string el: ineed){
            vector<string> &vec = ump[el];
            if(vec.size() == 0) continue;
            sort(vec.begin(), vec.end());
            for(auto e: vec){
                ans.push_back(e);
            }
        }

       
        return ans;
    }
};