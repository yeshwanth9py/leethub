// Last updated: 6/11/2026, 11:12:53 AM
class Solution {
public:
    int maxDistinct(string s) {
        unordered_map<char, int> ump;
        for(char ch: s){
            ump[ch]++;
        }

        // cout<<;
        return ump.size();
        
    }
};