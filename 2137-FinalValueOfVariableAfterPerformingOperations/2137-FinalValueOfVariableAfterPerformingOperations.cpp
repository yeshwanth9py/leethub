// Last updated: 6/11/2026, 11:24:42 AM
class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int ans = 0;
        unordered_map<string, int> ump= {{"++X", 1}, {"X++", 1}, {"--X", -1}, {"X--", -1}};
        for(string s: operations){
            ans += ump[s];
        }
        return ans;
    }
};