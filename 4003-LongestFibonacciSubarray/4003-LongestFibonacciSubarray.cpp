// Last updated: 6/11/2026, 11:14:01 AM
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        if(nums.size()<=2) return nums.size();
        int n = nums.size();
        int i=0; 
        int j=1;
        int rs = nums[i] + nums[j];
        int ans = 2;
        while(i<n){
            while(j+1<n && rs == nums[j+1]){
                j++;
                rs = nums[j]+nums[j-1];
            }
            if(j-i+1>=2){
                ans = max(ans, j-i+1);
            }
            i = j;
            j = j+1;
            if(j>=n) break;
            rs = nums[j] + nums[j-1];
        }
        return ans;
    }
};