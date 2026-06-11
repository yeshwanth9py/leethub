// Last updated: 6/11/2026, 11:13:08 AM
class Solution {
public:
    string lexSmallest(string s) {
        string sm = "";
        string ans = "";
        
        string prev = "";
        int n = s.length();
        for(int i=0; i<s.length(); i++){
            string next = s.substr(i, n-i);
            reverse(prev.begin(), prev.end());
            string full = prev + next;
            if(ans == "" || full<ans){
                ans = full;
            }
            reverse(prev.begin(), prev.end());
            reverse(next.begin(), next.end());
            full = prev + next;
            if(ans == "" || full<ans){
                ans = full;
            }
            prev.push_back(s[i]);
        }

        return ans;
    }
    
};