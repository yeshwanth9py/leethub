// Last updated: 6/11/2026, 11:37:38 AM
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curs = 0;
        int maxsum = nums[0];
        int n = nums.size();
        for(int i=0; i<n; i++){
            curs += nums[i];
            maxsum = max(maxsum, curs);
            if(curs<0){
                curs = 0;
            }
        }
        return maxsum;

    }
};