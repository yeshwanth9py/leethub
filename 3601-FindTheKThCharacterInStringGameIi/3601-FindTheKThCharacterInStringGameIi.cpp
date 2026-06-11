// Last updated: 6/11/2026, 11:17:41 AM
class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
    int mutations = 0;
    for (int op = log2(k); op >= 0; --op)
        if (k > 1LL << op) {
            k-= 1LL << op;
            mutations += operations[op];
        }
    return 'a' + mutations % 26;
}
};