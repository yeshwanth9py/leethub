// Last updated: 6/11/2026, 11:10:54 AM
class Solution {
public:
    int residuePrefixes(string s) {
        int cnt = 0;
        for(int l=1; l<=s.size(); l++){
            string pref = s.substr(0, l);
            set<char> st;
            for(char ch: pref){
                st.insert(ch);
            }
            if(st.size() == pref.size()%3){
                cnt++;
            }
        }
        return cnt;
    }
};