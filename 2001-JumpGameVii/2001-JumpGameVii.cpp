// Last updated: 6/11/2026, 11:25:25 AM
class Solution {
public:
    bool canReach(string s, int mnj, int mxj) {
        int n = s.size();
        vector<int> ans(n+1, 0);
        if(s.back()== '1') return 0;
        ans[0] = 1;
        int tot = 0;
        for(int i=mnj; i<n; i++){
            tot += ans[i-mnj];
            if(i-mxj-1>=0) tot -= ans[i-mxj-1];
            if(s[i] == '0') ans[i] = tot>0;
        }
        return ans[n-1];
    }
};