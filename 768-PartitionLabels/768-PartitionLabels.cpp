// Last updated: 6/11/2026, 11:31:23 AM
class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> ump;
        int n = s.length();
        for(int i=0; i<n; i++){
            ump[s[i]] = i;
        }

        vector<int> ans;
        int rmj = ump[s[0]];
        int pj = 0;
        for(int i=0; i<n; i++){
            rmj = max(rmj, ump[s[i]]);
            if(rmj == i){
                ans.push_back(i-pj+1);
                rmj = -1;
                pj = i+1;
            }
        }

        return ans;
        
    }
};