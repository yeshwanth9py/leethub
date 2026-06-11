// Last updated: 6/11/2026, 11:28:19 AM
class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> res(n);
        res[0] = n * (1 - n) / 2;
        for (int i = 1; i < n; ++i)
            res[i] = i;
        return res;
    }
};