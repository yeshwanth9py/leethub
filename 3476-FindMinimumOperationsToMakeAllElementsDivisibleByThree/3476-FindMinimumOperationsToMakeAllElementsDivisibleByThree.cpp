// Last updated: 6/11/2026, 11:18:04 AM
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int op = 0;
        for(int el: nums){
            if(el%3 == 0) continue;
            op++;  
        }
        return op;
    }
};