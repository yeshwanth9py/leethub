// Last updated: 6/11/2026, 11:36:59 AM
class Solution {
public:
    set<vector<int>> ans;
    void rec(int ind, vector<int> temp, vector<int>& nums){
        if(ind == nums.size()){
            ans.insert(temp);
            return;
        }
        temp.push_back(nums[ind]);
        rec(ind+1, temp, nums);
        temp.pop_back();
        rec(ind+1, temp, nums);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> temp;
        sort(nums.begin(), nums.end());
        ans.clear();
        rec(0, temp, nums);
        vector<vector<int>> ans2(ans.begin(), ans.end());
        return ans2;
    }
};