// Last updated: 6/11/2026, 11:15:56 AM
class Solution {
public:
    int maxSum(vector<int>& nums) {
        int i = 0;
        int j = -1;
        int n = nums.size();
        unordered_set<int> allnums;
        int tsum = 0;

        for(int i=0; i<n; i++){
            if(nums[i]<=0) continue;
            if(allnums.find(nums[i])==allnums.end()){
                tsum += nums[i];
                allnums.insert(nums[i]);
            }
        }
        if(allnums.empty()){
            int x = *max_element(nums.begin(), nums.end());
            return x;
        }

        return tsum;
    }
};