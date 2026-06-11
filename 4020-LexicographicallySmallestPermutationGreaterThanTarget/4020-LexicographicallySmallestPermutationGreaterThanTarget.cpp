// Last updated: 6/11/2026, 11:13:47 AM
class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        multiset<char> ms;
        for(char ch: s) ms.insert(ch);
        vector<string> ans;
        string pre = "";
        for(int i=0; i<s.size(); i++){
            auto gte = ms.upper_bound(target[i]);
            if(gte != ms.end()){
                char ch = *gte;
                string temp = pre;
                temp.push_back(ch);
                ms.erase(gte);
                for(char ch: ms){
                    temp.push_back(ch);
                }
                ans.push_back(temp);
                ms.insert(ch);
            }

            if(ms.find(target[i]) != ms.end()){
                ms.erase(ms.find(target[i]));
                pre.push_back(target[i]);
            }else{
                break;
            }
        }

        sort(ans.begin(), ans.end());
        if(ans.empty()) return "";
        return ans[0];
    }
};