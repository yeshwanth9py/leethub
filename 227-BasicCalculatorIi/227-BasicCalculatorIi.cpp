// Last updated: 6/11/2026, 11:34:34 AM
class Solution {
public:
    int calculate(string s) {
        int num = 0;
        char prevop = '+';

        stack<int> st;
        st.push(0);
        for(int i=0; i<s.size(); i++){
            char ch = s[i];
            if(ch >= '0' && ch<='9'){
                num = num*10 + (ch-'0');
            }

            if((!isdigit(ch) && ch!=' ' )|| i == s.size()-1){
                if(prevop == '+'){
                    st.push(num);
                }else if(prevop == '-'){
                    st.push(-num);
                }else if(prevop == '*'){
                    int val = st.top()*num;
                    st.pop();
                    st.push(val);
                }else if(prevop == '/'){
                    int val = st.top()/num;
                    st.pop();
                    st.push(val);
                }
                num = 0;
                prevop = ch;
            }


        }

        int totsum = 0;
        while(!st.empty()){
            totsum += st.top();
            st.pop();
        }
        return totsum;
    }
};