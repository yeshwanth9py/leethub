// Last updated: 6/11/2026, 11:22:55 AM
class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int j = -1;
        int i = 0;
        int n = nums.size();
        long long csum = 0;
        long long ans = 0;
        while(i<n){
            while(j+1<n && ((csum+nums[j+1])*(j+1-i+1))<k){
                j++;
                csum += nums[j];
            }

            if(j-i+1>=0){
                ans += (j-i+1);
            }

            if(i>j){
                i++;
                j=i-1;
            }else{
                csum -= nums[i];
                i++;
            }
        }

        return ans;
    }
};