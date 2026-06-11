// Last updated: 6/11/2026, 11:28:03 AM
class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [&](int a, int b){
            if(__builtin_popcount(a)!= __builtin_popcount(b)){
                return __builtin_popcount(a)<__builtin_popcount(b);
            }
            return a<b;
        });
        return arr;
    }
};