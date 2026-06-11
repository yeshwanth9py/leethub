// Last updated: 6/11/2026, 11:10:45 AM
class Solution {
public:
    int minimumPrefixLength(vector<int>& nums) {
        int n = nums.size();

        int lel = nums.back();
        for(int i=n-2; i>=0; i--){
            if(nums[i]<lel){
                lel = nums[i];
                continue;
            }else{
                return (i+1);
            }
        }

        return 0;
    }
};