// Last updated: 6/11/2026, 11:35:36 AM
class Solution {
public:
    bool isoperator(string ch){
        return (ch == "+" || ch=="-" || ch=="*" || ch=="/");
    }
    
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(int i=0; i<tokens.size(); i++){
            if(isoperator(tokens[i])){
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                if(tokens[i] == "+"){
                    st.push(a+b);
                }else if(tokens[i] == "-"){
                    st.push(b-a);
                }else if(tokens[i] == "*"){
                    st.push(a*b);
                }else{
                    st.push(b/a);
                }
            }else{
                st.push(stoi(tokens[i]));
            }
        }

        return st.top();
    }
};