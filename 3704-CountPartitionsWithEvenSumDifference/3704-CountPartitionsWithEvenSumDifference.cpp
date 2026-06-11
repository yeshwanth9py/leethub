// Last updated: 6/11/2026, 11:16:43 AM
class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int totsum = accumulate(nums.begin(), nums.end(), 0);
        int leftsum = 0;
        int rightsum = totsum;
        int cnt = 0;
        for(int i=0; i<nums.size()-1; i++){
            leftsum += nums[i];
            rightsum -= nums[i];
            if(abs(leftsum-rightsum)%2==0){
                cnt++;
            }
        }
        return cnt;
    }
};