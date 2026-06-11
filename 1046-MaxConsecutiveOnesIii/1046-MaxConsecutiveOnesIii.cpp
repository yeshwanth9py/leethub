// Last updated: 6/11/2026, 11:29:50 AM
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i=0;
        int j=-1;
        int n = nums.size();
        int fl= 0;
        int ans= 0;
        while(i<n){
            while(j+1<n && fl+(nums[j+1] == 0)<=k){
                j++;
                if(nums[j] == 0){
                    fl++;
                }
            }
            ans = max(ans, j-i+1);

            if(i>j){
                i++;
                j=i-1;
            }else{
                if(nums[i] == 0){
                    fl--;
                }
                i++;
            }
        }

        return ans;
    }
};