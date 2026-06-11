// Last updated: 6/11/2026, 11:13:38 AM
class Solution {
public:
    vector<int> decimalRepresentation(int n) {
        vector<int> ans;
        long long cnt = 1;
        while(n){
            int ld = n%10;
            n = n/10;
            if(ld != 0){
                ld = ld*cnt;
                ans.push_back(ld);   
            }
            cnt = 1LL*cnt*10;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};