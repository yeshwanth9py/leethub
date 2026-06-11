// Last updated: 6/11/2026, 11:26:40 AM
class Solution {
public:
    int minimumDeletions(string s) {
        int rem = 0;
        int noa = 0;
        int n = s.size();
        for(int i=0; i<s.size(); i++){
            if(s[i] == 'a') noa++;
        }
        int ans = n;
        for(int i=0; i<n; i++){
            if(s[i] == 'b'){
                ans = min(ans, rem+noa);
                rem++;
            }else{
                noa--;
            }
        }
        ans = min(ans, rem);

        return ans;


    }
};