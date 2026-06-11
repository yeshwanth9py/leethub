// Last updated: 6/11/2026, 11:35:23 AM
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int i = 0;
        int j = -1;
        int n = s.length();
        unordered_map<string, int> ump;
        while(i<n){
            while(j+1<n && j+1-i+1<=10){
                j++;
            }

            if(j-i+1==10){
                string res = s.substr(i, 10);
                ump[res]++;
            }

            i++;
        }

        vector<string> ans;
        for(auto item: ump){
            if(item.second>1){
                ans.push_back(item.first);
            }
        }

        return ans;
    }
};