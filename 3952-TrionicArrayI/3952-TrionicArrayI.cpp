// Last updated: 6/11/2026, 11:14:33 AM
class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        if(nums[0]>=nums[1]) return 0;
        int i = 0;
        while(i<n-1){
            if(nums[i]>=nums[i+1]){
                break;
            }
            i++;
        }
        cout<<i<<endl;
        if(i+1 >= n-1) return 0;
        

        if(nums[i]<=nums[i+1]) return 0;

        while(i<n-1){
            if(nums[i]<=nums[i+1]){
                break;
            }
            i++;
        }
        cout<<i<<endl;
        if(i+1 >= n) return 0;
        if(nums[i]>=nums[i+1]) return 0;

        while(i<n-1){
            if(nums[i]>=nums[i+1]){
                return 0;
            }
            i++;
        }

        return 1;

    }
};