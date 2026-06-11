// Last updated: 6/11/2026, 11:20:10 AM
class Solution {
public:
    int countWays(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans = 0;
        for(int i = 0;i<nums.size();i++){
            if((nums[i]<(i+1))&&(((i+1)<nums.size())&&(nums[i+1]>(i+1)))){
                ans++;
            }
            else if(( nums[i]<(i+1))&&((i+1) == nums.size())){
                ans++;
            }
        }
        if(nums[0]>0){
            ans++;
        }
        return ans;
    }
};