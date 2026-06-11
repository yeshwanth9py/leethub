// Last updated: 6/11/2026, 11:09:03 AM
class Solution {
public:
    bool isAdjacentDiffAtMostTwo(string s) {
        for(int i=0; i<s.size()-1; i++){
            if(abs(s[i]-s[i+1]) > 2) return 0;
            // cout<<s[i]-s[i+1]<<" ";
        }
        return 1;
    }
};