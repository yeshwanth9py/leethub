// Last updated: 6/11/2026, 11:28:51 AM
class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> st;
        int n = s.size();
        int i = 0;
        int j = -1;
        while(i<n){
            while(j+1<n && s[j+1] == s[i]){
                j++;
            }
            if(j-i+1>0){
                char hc = s[j];
                int cnt = j-i+1;
                cnt = cnt%k;
                if(cnt == 0){
                    //
                }
                else if(!st.empty() && st.top().first == hc){
                    st.top().second =  (st.top().second + cnt)%k;
                    if(st.top().second == 0){
                        st.pop();
                    }
                }else{
                    st.push({hc, cnt});
                }
            }
            if(i>j){
                i++;
                j=i-1;
            }else{
                i = j+1;
            }
        }

        string ans = "";
        while(!st.empty()){
            auto [cur, cnt] = st.top(); st.pop();
            string temp = string(cnt, cur);
            cout<<temp<<" ";
            ans += temp;
        }
        reverse(ans.begin(), ans.end());

        return ans;
        
    }
};