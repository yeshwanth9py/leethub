// Last updated: 6/11/2026, 11:11:05 AM
class Solution {
public:
    string reversePrefix(string s, int k) {
        string temp = s.substr(0, k);
        reverse(temp.begin(), temp.end());

        temp = temp + s.substr(k);

        return temp;
        
    }
};