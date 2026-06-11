// Last updated: 6/11/2026, 11:12:31 AM
class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mx = *(max_element(nums.begin(), nums.end()));
        int sum = 0;
        for(int el: nums){
            sum += (mx-el);
        }

        return sum;
    }
};