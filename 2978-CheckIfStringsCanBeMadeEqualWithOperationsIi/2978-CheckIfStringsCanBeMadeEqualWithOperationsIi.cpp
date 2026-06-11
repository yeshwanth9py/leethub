// Last updated: 6/11/2026, 11:20:32 AM
class Solution {
public:
    string convert(string &s){
        string f = "";
        string sec = "";
        for(int i=0; i<s.size(); i++){
            if(i%2 == 0){
                f.push_back(s[i]);
            }else{
                sec.push_back(s[i]);
            }
        }
        sort(f.begin(), f.end());
        sort(sec.begin(), sec.end());
        f = f+sec;
        return f;
    }
    bool checkStrings(string s1, string s2) {
        s1 = convert(s1);
        s2 = convert(s2);
        return s1 == s2;
    }
};
