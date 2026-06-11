// Last updated: 6/11/2026, 11:26:59 AM
class Solution {
public:
    int longestAwesome(string s) {
        vector<int> seen(1025, -2);
        
        int mask = 0;
        int res = 0;
        seen[0] = -1;
        for(int i=0; i<s.length(); i++){
            mask ^= (1LL<<(s[i]-'0'));
            if(seen[mask] != -2){
                res = max(res, i-seen[mask]);
            }
            for(int j=0; j<10; j++){
                int temp = (mask^(1LL<<j));
                if(seen[temp] != -2){
                    res = max(res, i-seen[temp]);
                }
            }
            if(seen[mask]==-2){
                seen[mask] = i;
            }
        }

        return res;



    }
};