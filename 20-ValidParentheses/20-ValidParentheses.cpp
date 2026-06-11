// Last updated: 6/11/2026, 11:38:25 AM
class Solution {
public:
    unordered_map<char, char> ump;
    bool isValid(string s) {
        ump['{'] = '}';
        ump['('] = ')';
        ump['['] = ']';

        stack<char> st;

        for(char ch: s){
            if(ump.find(ch) != ump.end()){
                st.push(ch);
            }else{
                if(!st.empty() && ump[st.top()] == ch){
                    st.pop();
                    continue;
                }else{
                    return 0;
                }
            }
        }

        return (st.empty() == 1);

    }
};