// Last updated: 6/11/2026, 11:16:52 AM
class Solution {
public:
    int smallestNumber(int n) {
        int sz = log2(n)+1;
        int ans = (1LL<<sz)-1;
        cout<<(ans)<<endl;
        return ans;
    }
};