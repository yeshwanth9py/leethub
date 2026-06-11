// Last updated: 6/11/2026, 11:24:14 AM
class Solution {
public:
    long long countVowels(string s) {
        int n = s.size();
        long long ans = 0;
        for(int i=0; i<n; i++){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
                ans += 1LL*(i+1)*(n-i);
            }
        }

        return ans;
    }
};