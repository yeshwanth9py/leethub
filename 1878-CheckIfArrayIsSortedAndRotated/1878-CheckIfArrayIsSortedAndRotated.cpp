// Last updated: 6/11/2026, 11:26:05 AM
class Solution {
public:
    bool check(vector<int>& nums) {
        
        int n = nums.size();

        bool pk = 0;
        for(int i=1; i<n;){
            if(nums[i]>=nums[i-1]){
                i++;
                continue;
            }else{
                if(pk) return 0;
                pk = 1;
                // i++;
                if(i<n && nums[i]<=nums[n-1] && nums[n-1]<=nums[0]){
                    i++;
                }else{
                    return 0;
                }
            }
        }

        return 1;
        

    }
};