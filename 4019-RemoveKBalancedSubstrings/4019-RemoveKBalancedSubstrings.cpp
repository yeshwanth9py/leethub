// Last updated: 6/11/2026, 11:13:48 AM
class Solution {
public:
    string removeSubstring(string s, int k) {
        int n = s.length();
        vector<int> dp(n, -1);
        vector<int> cnt(n, 0);
        vector<int> block(n, 0);
        
        for(int i=n-1; i>=0; i--){
            if(s[i] == ')'){
                cnt[i] = 1+((i+1<n)?cnt[i+1]:0);
            }
        }
        
        stack<int> st;
        for(int i=0; i<n; i++){
            if(block[i] == 1) continue;
            if(s[i] == '('){
                if(st.size()>0 && s[st.top()] == '('){
                    dp[i] = dp[st.top()]+1;
                }else{
                    dp[i] = 1;
                }
                st.push(i);
            }else{
                if(st.size()>0 && s[st.top()] == '(' && dp[st.top()]>=k && cnt[i] >=k){
                    for(int j=0; j<k; j++){
                        st.pop();
                        if(i+j<n) block[i+j] = 1;
                    }
                }else if(st.size()>0 && s[st.top()] == ')' && dp[st.top()] == 1){
                    for(int j=0; j<2*k-1; j++){
                        st.pop();
                    }
                }
                else{
                    if(st.size()>0 && st.size()>0 && s[st.top()] == ')'){
                        if(dp[st.top()] > 0){
                            dp[i] = dp[st.top()]-1;
                        }else{
                            dp[i] = -1;
                        }
                    }else{
                        if(st.size()>0 && dp[st.top()]>=k){
                            dp[i] = k-1;
                        }else{
                            dp[i] = -1;
                        }
                    }
                    st.push(i);
                }
            }
        }

        string ans = "";
        while(!st.empty()){
            ans.push_back(s[st.top()]);
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
        
    }
};