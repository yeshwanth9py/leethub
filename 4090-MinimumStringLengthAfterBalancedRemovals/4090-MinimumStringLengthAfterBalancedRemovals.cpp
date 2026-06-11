// Last updated: 6/11/2026, 11:12:50 AM
class Solution {
public:
    int minLengthAfterRemovals(string s) {
        int n = s.size();
        int cnt = 0;
        for(int i=0; i<n; i++){
            if(s[i] == 'a'){
                cnt++;
            }else{
                cnt--;
            }
        }
        return abs(cnt);
    }
};