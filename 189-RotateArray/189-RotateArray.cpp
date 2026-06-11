// Last updated: 6/11/2026, 11:35:18 AM
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k%(nums.size());

        vector<int> tempv(nums.end()-k, nums.end());
        nums.erase(nums.end()-k, nums.end());
        nums.insert(nums.begin(), tempv.begin(), tempv.end());

    }
};