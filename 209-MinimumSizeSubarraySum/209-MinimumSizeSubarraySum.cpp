// Last updated: 6/11/2026, 11:34:50 AM
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i=0;
        int j=-1;
        int n = nums.size();
        int cs = 0;
        int minl = 1e9;
        while(i<n){
            while(j+1<n && cs<target){
                j++;
                cs += nums[j];
                // cout<<cs<<" ";
            }
            if(j-i+1>0 && cs>=target){
                minl = min(minl, j-i+1);
            }
            if(i>j){
                i++;
                j = i-1;
                cs = 0;
            }else{
                cs -= nums[i];
                i++;
            }
        }

        if(minl>=1e9) return 0;
        return minl;
    }
};