// Last updated: 6/11/2026, 11:22:54 AM
class Solution {
public:
    int longestSubsequence(string s, int k) {

        int curval = 0;
        int len = 0;
        int n = s.length();
        long long pow = 1;
        for(int i=s.length()-1; i>=0; i--){
            if(s[i]=='1'){
                if(n-i-1<32 && k>0 && (1LL<<(n-i-1))<=k){
                    len++;
                    k = k-(1LL<<(n-i-1));
                }
            }else{
                len++;
            }
        }

        return len;
    }
};