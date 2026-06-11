// Last updated: 6/11/2026, 11:38:54 AM
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> um;

        for(int i=0; i<nums.size(); i++){
            if(um.find(target-nums[i])!=um.end()){
                return {i, um[target-nums[i]]};
            }
            um[nums[i]] = i;
        }

        return {-1, -1};

       
    }
};