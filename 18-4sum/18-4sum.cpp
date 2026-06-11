// Last updated: 6/11/2026, 11:38:32 AM
using ll = long long;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        int n = nums.size();
        
        if (n < 4) return result;

        // Sort the array to make skipping duplicates and two-pointer approach easier
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue; // Skip duplicates for i
            
            for (int j = i + 1; j < n - 2; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue; // Skip duplicates for j
                
                ll cur_sum = (ll)nums[i] + nums[j];
                ll targ_reqd = (ll)target - cur_sum;
                
                int left = j + 1, right = n - 1;
                while (left < right) {
                    ll two_sum = (ll)nums[left] + nums[right];
                    
                    if (two_sum == targ_reqd) {
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});
                        
                        // Move pointers and skip duplicates
                        while (left < right && nums[left] == nums[left + 1]) left++;
                        while (left < right && nums[right] == nums[right - 1]) right--;
                        
                        left++;
                        right--;
                    } else if (two_sum < targ_reqd) {
                        left++;
                    } else {
                        right--;
                    }
                }
            }
        }
        
        return result;
    }
};
