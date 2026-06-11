// Last updated: 6/11/2026, 11:24:03 AM
class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int li = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        int ui = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
        ui = ui-1;
        if(li<nums.size() && nums[li] != target){
            return {};
        }
        vector<int> ans;
        for(int i=li; i<=ui; i++){
            ans.push_back(i);
        }
        return ans;
        
    }
};