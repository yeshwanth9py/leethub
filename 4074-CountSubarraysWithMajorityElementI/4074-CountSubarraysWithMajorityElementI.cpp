// Last updated: 6/11/2026, 11:13:07 AM
class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == target){
                nums[i] = 1;
            }else{
                nums[i] = -1;
            }
        }

        int cnt = 0;

        //no of subarry sums > 0
        for(int i=0; i<nums.size(); i++){
            int sum = 0;
            for(int j=i; j<nums.size(); j++){
                sum += nums[j];
                if(sum>0){
                    cnt++;
                }
            }
        }
        
        return cnt;
    }
};