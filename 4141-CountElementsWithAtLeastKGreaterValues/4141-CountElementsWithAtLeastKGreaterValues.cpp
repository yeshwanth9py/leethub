// Last updated: 6/11/2026, 11:12:04 AM
class Solution {
public:
    int countElements(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = 0;
        if(k == 0) return n;
        for(int i=0; i<n; i++){
            auto it = upper_bound(nums.begin(), nums.end(), nums[i]);
            if(it == nums.end()) continue;
            int mog = n-(it-nums.begin());
            if(mog>=k) ans++;
        }

        return ans;
    }
};