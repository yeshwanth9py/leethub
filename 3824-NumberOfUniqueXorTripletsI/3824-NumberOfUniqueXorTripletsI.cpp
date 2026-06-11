// Last updated: 6/11/2026, 11:15:25 AM
class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if(n<3){
            return n;
        }
        int L = 32 - __builtin_clz(n);
        return (1<<L);
    }
};