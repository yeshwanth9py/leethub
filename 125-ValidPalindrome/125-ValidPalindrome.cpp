// Last updated: 6/11/2026, 11:36:15 AM
class Solution {
public:
    bool ispalindrome(string s){
        cout<<s<<endl;
        int i =0;
        int j = s.size()-1;
        while(i<=j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    bool isPalindrome(string s) {
        string ans = "";
        string temp = "";
       for(int i=0; i<s.size(); i++){
            if(s[i]>='a' && s[i]<='z'){
                temp += s[i];
            }

            else if(s[i]>='A' && s[i]<='Z'){
                temp += static_cast<char> (s[i]+('a'-'A'));
            }
            else if(s[i]>='0' && s[i]<='9'){
                temp += s[i];
            }

            else if(s[i] == ' '){
                ans += temp;
                temp = "";
            }
       }

       if(temp!=""){
            ans += temp;
            temp = "";
       }

       return ispalindrome(ans);
    }
};