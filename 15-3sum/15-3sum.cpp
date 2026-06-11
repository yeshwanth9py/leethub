// Last updated: 6/11/2026, 11:38:36 AM
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> ans;
        for (int i = 0; i < nums.size() - 2; i++) {
            int cur = i;
            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right) {
                if (nums[cur] + nums[left] + nums[right] == 0) {
                    ans.insert({nums[cur], nums[left], nums[right]});
                    left++;
                }else if (nums[cur] + nums[left] + nums[right] > 0) {
                    right--;
                }else{
                    left++;
                }
            }
        }
        return vector<vector<int>>(ans.begin(), ans.end());
    }
        
};