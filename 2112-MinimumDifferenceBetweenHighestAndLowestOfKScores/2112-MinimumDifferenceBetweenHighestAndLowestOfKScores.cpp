// Last updated: 6/11/2026, 11:24:59 AM
class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int s = 0;
        int mind = 1e9;
        for(int i=k-1; i<n; i++){
            int dif = nums[i]-nums[s];
            mind = min(mind, dif);
            s++;
        }

        return mind;

    }
};