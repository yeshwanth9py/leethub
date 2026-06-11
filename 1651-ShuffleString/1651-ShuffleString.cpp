// Last updated: 6/11/2026, 11:27:07 AM
class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        string c = s;
        int n = indices.size();
        for(int i=0; i<n; i++){
            c[indices[i]] = s[i];
        }

        return c;
    }
};