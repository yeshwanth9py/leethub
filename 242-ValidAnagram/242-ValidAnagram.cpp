// Last updated: 6/11/2026, 11:34:12 AM
class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s== t;
    }
};