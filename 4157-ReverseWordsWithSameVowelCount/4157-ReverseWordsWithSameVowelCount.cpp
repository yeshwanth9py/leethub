// Last updated: 6/11/2026, 11:11:24 AM
class Solution {
public:
    int getcount(string s){
        int cnt = 0;
        for(char ch: s){
            if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o'  || ch == 'u'){
                cnt++;
            }
        }
        return cnt;
    }
    string reverseWords(string s) {
        istringstream iss(s);
        string token;
        vector<string> all;
        while(iss>>token){
            all.push_back(token);
        }
        int cnt = getcount(all[0]);
        string ans = "";
        for(int i=0; i<all.size(); i++){
            if(i == 0){
                ans+=all[i];
            }else if(getcount(all[i]) == cnt){
                reverse(all[i].begin(), all[i].end());
                ans+=" "+all[i];
            }else{
                ans+=" "+all[i];
            }
        }

        return ans;
    }
};