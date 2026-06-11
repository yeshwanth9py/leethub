// Last updated: 6/11/2026, 11:27:43 AM
class Solution {
public:
   int findLucky(vector<int>& arr) {
    int m[501] = {};
    for (auto n : arr)
        ++m[n];
    for (auto n = arr.size(); n > 0; --n)
        if (n == m[n])
            return n;
    return -1;
}
};