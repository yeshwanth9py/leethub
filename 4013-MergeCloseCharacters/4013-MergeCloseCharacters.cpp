// Last updated: 6/11/2026, 11:13:52 AM
class Solution {
public:
    string mergeCharacters(string s, int k) {
        unordered_map<char, pair<int, int>> ump;
        stack<char> st;
        int mh = 0;
        for(int i=0; i<s.size(); i++){
            char ch = s[i];
            if(ump.find(ch)!=ump.end() && i-ump[ch].first-(mh-ump[ch].second)<=k){
                mh++;
                // cout<<ump[ch]<<" "<<i<<endl;
                continue;
            }else{
                ump[ch] = {i, mh};
                st.push(ch);
            }
        }

        string ans = "";
        while(!st.empty()){
            char ch = st.top(); st.pop();
            ans.push_back(ch);
        }

        reverse(ans.begin(), ans.end());

        return ans;
        
    }
};