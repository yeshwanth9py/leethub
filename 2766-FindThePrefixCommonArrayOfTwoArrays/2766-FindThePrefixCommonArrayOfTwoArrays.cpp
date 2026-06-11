// Last updated: 6/11/2026, 11:20:56 AM
class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& a, vector<int>& b) {
        int n = a.size();
        vector<int> perm(n+1, 0);
        int common = 0;
        vector<int> ans;
        for(int i=0; i<n; i++){
            perm[a[i]]++;
            if(perm[a[i]] == 2){
                common++;
            }
            perm[b[i]]++;
            if(perm[b[i]] == 2){
                common++;
            }
            ans.push_back(common);
        }

        return ans;
    }
};