// Last updated: 6/11/2026, 11:33:17 AM
class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<int> st;
        int n = num.size();
        //012345
        int rem = n-k;  //sz i want to form
        if(rem == 0) return "0";
        //561234
        for(int i=0; i<n; i++){
            int ch = num[i]-'0';
            while(!st.empty() && st.top()>ch && st.size()-1+(n-i)>=rem){  //if i can remove top elem and still form rem elements
                st.pop();
            }
            st.push(ch);
        }
        
        string ans = "";

        while(!st.empty() && st.size()>rem){
            st.pop();
        }

        while(!st.empty()){
            ans.push_back(st.top()+'0');
            st.pop();
        }

        while(ans.size()>0 && ans.back() == '0') ans.pop_back();

        reverse(ans.begin(), ans.end());
        
        if(ans == "") return "0";
        return ans;
    }
};