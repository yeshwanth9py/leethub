// Last updated: 6/11/2026, 11:11:14 AM
class Solution {
public:
    int mirrorDistance(int n) {
        string a = to_string(n);
        reverse(a.begin(), a.end());
        int dnum = stoi(a);
        return abs(n-dnum);
    }
};