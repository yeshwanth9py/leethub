// Last updated: 6/11/2026, 11:24:47 AM
class Solution {
public:
    string s;
    bool ispalind(string &s1){
        int i=0;
        int j = s1.length()-1;
        while(i<j){
            if(s1[i]!=s1[j]){
                return 0;
            }
            i++;
            j--;
        }
        return 1;
    }

    int backtrack(int ind, string &s1, string &s2){
        if(ind == s.length()){
            if(ispalind(s1) && ispalind(s2)){
                return s1.length()*s2.length();
            }
            return 0;
        }

        int ans = backtrack(ind+1, s1, s2);
        s1 += s[ind];
        ans = max(ans, backtrack(ind+1, s1, s2));
        s1.pop_back();
        s2 += s[ind];
        ans = max(ans, backtrack(ind+1, s1, s2));
        s2.pop_back();

        return ans;
    }

    int maxProduct(string s) {
        this->s = s;
        string s1 = "";
        string s2 = "";
        return backtrack(0, s1, s2);
    }
};