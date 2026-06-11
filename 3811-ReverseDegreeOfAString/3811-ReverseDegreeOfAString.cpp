// Last updated: 6/11/2026, 11:15:34 AM
class Solution {
public:
    int reverseDegree(string s) {
        int ans = 0;
        
        for(int i=0; i<s.length(); i++){
            // cout<<s[i]<<" "<<(25-(s[i]-'a')+1)<<endl;
            ans += ((25-(s[i]-'a')+1)*(i+1));
        }
        return ans;
    }
};



