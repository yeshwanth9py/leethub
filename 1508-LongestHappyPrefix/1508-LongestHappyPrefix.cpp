// Last updated: 6/11/2026, 11:27:46 AM
class Solution {
public:
    vector<int> gkmp(string s){
        int n = s.size();
        vector<int> kmp(n+1, 0);
        kmp[0] = -1;
        int i=0;
        int j=-1;
        while(i<n){
            while(j!=-1 && s[j]!=s[i]) j = kmp[j];
            i++; j++;
            kmp[i] = j;
        }

        return kmp;
    }

    string longestPrefix(string s) {
        vector<int> mykmp = gkmp(s);
        int ml = mykmp[s.size()];
        return s.substr(0, ml); 
    }
};