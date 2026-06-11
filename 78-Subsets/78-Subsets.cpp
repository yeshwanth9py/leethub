// Last updated: 6/11/2026, 11:37:06 AM
class Solution {
public:
    vector<vector<int>> ans;
    void rec(int ind, vector<int> temp, vector<int>& nums){
        if(ind == nums.size()){
            ans.push_back(temp);
            return;
        }
        
        rec(ind+1, temp, nums);
        temp.push_back(nums[ind]);
        rec(ind+1, temp, nums);
        temp.pop_back();
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        ans.clear();
        vector<int> temp;
        rec(0, temp, nums);
        return ans;
    }
};