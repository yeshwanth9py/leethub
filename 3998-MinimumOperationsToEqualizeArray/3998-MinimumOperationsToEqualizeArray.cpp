// Last updated: 6/11/2026, 11:14:06 AM
class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int, int> ump;
        for(int el: nums){
            ump[el] = 1;
        }
        if(ump.size() == 1){
            return 0;
        }
        return 1;
    }
};