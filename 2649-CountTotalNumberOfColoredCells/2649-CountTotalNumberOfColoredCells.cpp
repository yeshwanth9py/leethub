// Last updated: 6/11/2026, 11:21:30 AM
class Solution {
public:
    long long coloredCells(int n) {
        long long ans = 2LL*n*n - 2LL*n;
        ans += 1LL;
        return ans;
    }
};