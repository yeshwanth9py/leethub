// Last updated: 6/11/2026, 11:10:50 AM
class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& tar) {
        unordered_map<int, int> ump;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] != tar[i]){
                ump[nums[i]]++;
            }
        }

        return ump.size();
    }
};