// Last updated: 6/11/2026, 11:16:45 AM
class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int i=0;
        int n = nums.size();
        int ans = 0;
        for(int k=2; k<n; k++)
        {
            if((nums[k]+nums[i]) == nums[i+1]/2.0){
                // cout<<nums[i]<<" "<<nums[i+1]<<" "<<nums[k]<<endl;
                ans++;
            }
            i++;
        }
        return ans;
    }
};