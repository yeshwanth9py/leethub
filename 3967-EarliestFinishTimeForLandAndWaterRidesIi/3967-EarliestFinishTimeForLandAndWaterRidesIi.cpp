// Last updated: 6/11/2026, 11:14:24 AM
class Solution {
public:
    int earliestFinishTime(vector<int>& l, vector<int>& ld, vector<int>& w, vector<int>& wd) {
        int mtc = 1e9;
        for(int i=0; i<l.size(); i++){
            mtc = min(mtc, l[i]+ld[i]);
        }

        int ans = 1e9;
        for(int i=0; i<w.size(); i++){
            int cure = max(w[i], mtc) + wd[i];
            ans = min(ans, cure);
        }

        mtc = 1e9;
        for(int i=0; i<w.size(); i++){
            mtc = min(mtc, w[i]+wd[i]);
        }

        for(int i=0; i<l.size(); i++){
            int cure = max(mtc, l[i]) + ld[i];
            ans = min(ans, cure);
        }

        return ans;
    }
};