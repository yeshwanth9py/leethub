// Last updated: 6/11/2026, 11:12:54 AM
class Solution {
public:
    string lexSmallestAfterDeletion(string s) {
        unordered_map<char, int> ump;
        for(char ch: s){
            ump[ch]++;
        }
        int n = s.size();

        stack<char> st;
        for(int i=0; i<n; i++){
            char ch = s[i];
            while(!st.empty() && st.top()>s[i] && ump[st.top()]>1){
                ump[st.top()]--;
                st.pop();
            }
            st.push(ch);
        }

        string ans = "";
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        while(ans.size()>0 && ump[ans.back()]>1){
            ump[ans.back()]--;
            ans.pop_back();
        }
        
        return ans;
    }
};