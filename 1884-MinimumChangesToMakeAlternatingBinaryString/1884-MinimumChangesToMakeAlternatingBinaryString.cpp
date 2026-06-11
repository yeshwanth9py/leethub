// Last updated: 6/11/2026, 11:26:03 AM
class Solution {
public:
    int n;
    int minOperations(string s) {
        n = s.size();
        //0 1 0 1
        int need = 0;
        int need2 = 1;

        int ans = 0;
        int ans2 = 0;
        for(int i=0; i<n; i++){
            if(need != s[i]-'0'){
                ans++;
            }
            if(need2 != s[i]-'0'){
                ans2++;
            }
            need = !need;
            need2 = !need2;
        }

        return min(ans, ans2);
    }
}
;