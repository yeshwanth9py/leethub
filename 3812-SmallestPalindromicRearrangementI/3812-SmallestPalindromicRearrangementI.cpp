// Last updated: 6/11/2026, 11:15:33 AM
class Solution {
public:
    string smallestPalindrome(string s) {
        string ans = "";
        int n = s.length();
        if(n<=1){
            return s;
        }
        if(n%2 == 0){
            sort(s.begin(), s.begin()+(n/2));
            string temp = s.substr(0, n/2);
            ans = temp;
            reverse(temp.begin(), temp.end());
            ans += temp;
            return ans;
        }else{
            sort(s.begin(), s.begin()+(n/2));
            string temp = s.substr(0, n/2);
            ans = temp;
            ans += s[n/2];
            reverse(temp.begin(), temp.end());
            ans += temp;
            return ans;
        }
    }
};