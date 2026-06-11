// Last updated: 6/11/2026, 11:11:02 AM
class Solution {
public:
    string largestEven(string s) {
        while(s.size()>0 && (s.back()-'0')%2 != 0){
            s.pop_back();
        }

        return s;
    }
};