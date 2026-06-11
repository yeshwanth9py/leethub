// Last updated: 6/11/2026, 11:37:45 AM
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> ump;
        for(auto el: strs){
            string temp = el;
            sort(el.begin(), el.end());
            ump[el].push_back(temp);
        }

        vector<vector<string>> ans;

        for(auto el: ump){
            ans.push_back(el.second);
        }

        return ans;

        

    }
};