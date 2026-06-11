// Last updated: 6/11/2026, 11:25:21 AM
class Solution {
public:
    string removeOccurrences(string s, string part) {
        int d;
        while(s.find(part)!=string::npos){
            d = s.find(part);
            s.erase(d, part.length());
        }
        return s;
    }
};