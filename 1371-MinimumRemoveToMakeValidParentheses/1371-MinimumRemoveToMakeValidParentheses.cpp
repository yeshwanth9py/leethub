// Last updated: 6/11/2026, 11:28:40 AM
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;
        vector<int> isvalid(s.size(), 1);
        for(int i=0; i<s.size(); i++){
            if(s[i] == '('){
                st.push(i);
                isvalid[i] = 0;
            }else if(s[i] == ')'){
                if(!st.empty() && s[st.top()] == '('){
                    isvalid[st.top()] = 1;
                    st.pop();
                }else{
                    isvalid[i] = 0;
                }
            }
        }
        string oth = "";
        for(int i=0; i<s.size(); i++){
            if(isvalid[i]){
                oth.push_back(s[i]);
            }
        }

        return oth;
    }
};