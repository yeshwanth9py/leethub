// Last updated: 6/11/2026, 11:38:13 AM
class Solution {
public:
    int longestValidParentheses(string s) {
        int open = 0;
        int close = 0;
        int ans = 0;
        int n = s.size();
        for(int i=0; i<n; i++){
            if(s[i]=='('){
                open++;
            }else{
                close++;
            }

            if(close>open){
                close = 0;
                open = 0;
            }

            if(open == close){
                ans = max(ans, 2*open);
            }
        }

        open = close = 0;
        for(int i=n-1; i>=0; i--){
            if(s[i]=='('){
                open++;
            }else{
                close++;
            }

            if(close<open){
                close = 0;
                open = 0;
            }

            if(open == close){
                ans = max(ans, 2*open);
            }
        }

        return ans;




    }
};