// Last updated: 6/11/2026, 11:11:23 AM
class Solution {
public:
    int absDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int s1 = 0;
        int s2 = 0;
        int n = nums.size();
        for(int i=0; i<k; i++){
            s1 += nums[i];
        }

        for(int i=n-1; i>=n-k; i--){
            s2 += nums[i];
        }

        return abs(s1-s2);
        
    }
};