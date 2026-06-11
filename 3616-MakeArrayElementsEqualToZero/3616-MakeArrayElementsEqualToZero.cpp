// Last updated: 6/11/2026, 11:17:32 AM
class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n = nums.size();
        int rsum = accumulate(nums.begin(), nums.end(), 0);
        int lsum = 0;
        int cnt = 0;
        for(int i=0; i<n; i++){
            rsum -= nums[i];
            lsum += nums[i];
            if(nums[i] == 0){
                if(lsum == rsum){
                    cnt+=2;
                }else if(lsum==rsum+1 || rsum == lsum+1){
                    cnt+=1;
                }
            }
        }

        return cnt;
    }
};