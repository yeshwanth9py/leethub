// Last updated: 6/11/2026, 11:13:55 AM
class Solution {
public:
    int evenNumberBitwiseORs(vector<int>& nums) {
        int ans = 0;
        for(int el: nums){
            if(el%2 == 0){
                ans |= el;
            }
        }

        return ans;
    }
};