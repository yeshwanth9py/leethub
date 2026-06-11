// Last updated: 6/11/2026, 11:17:34 AM
class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> lis(n, 1);
        for(int i=n-2; i>=0; i--){
            if(nums[i]<nums[i+1]){
                lis[i] = 1+lis[i+1];
            }
        }
        for(int i=0; i<n; i++){
            cout<<lis[i]<<" ";
        }

        for(int i=0; i<n; i++){
            if(i+k<n && lis[i]>=k && lis[i+k]>=k){
                return 1;
            }
        }

        return 0;
    }

};